#include <string>
#include <iostream>
#include "headers/data.h"
#include "headers/utils.h"
#include "headers/portfolio.h"

using namespace std;

InvestmentNode *createInvestmentNode(const Investment &investment)
{
  InvestmentNode *newNode = new InvestmentNode;
  newNode->data = investment;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  return newNode;
}

void displayAllInvestments(vector<Portfolio> &portfolios)
{
  string portfolioCode;
  cout << "Enter the code of the portfolio to display investments: ";
  getline(cin, portfolioCode);

  const Portfolio *portfolio = findPortfolioByCode(portfolios, portfolioCode);
  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << portfolioCode << " not found.\n";
    return;
  }

  if (portfolio->head == nullptr)
  {
    cout << "\nPortfolio " << portfolio->name << " does not contain any investments.\n";
    return;
  }

  cout << "\nAll Investments in Portfolio " << portfolio->name << ":\n";
  InvestmentNode *current = portfolio->head;
  while (current != nullptr)
  {
    cout << "Code: " << current->data.code << endl;
    cout << "Name: " << current->data.name << endl;
    cout << "Type: " << (current->data.type == CRYPTOCURRENCY ? "Cryptocurrency" : "Stock") << endl;
    cout << "Purchase Price: " << current->data.purchasePrice << endl;
    cout << "Current Value: " << current->data.currentValue << endl;
    cout << "Quantity: " << current->data.quantity << endl;
    cout << endl;
    current = current->next;
  }
}

void createInvestment(vector<Portfolio> &portfolios)
{
  string portfolioCode;
  cout << "\nEnter the code of the portfolio to add the investment: ";
  getline(cin, portfolioCode);

  Portfolio *portfolio = findPortfolioByCode(portfolios, portfolioCode);
  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << portfolioCode << " not found.\n";
    return;
  }

  Investment investment;
  investment.code = generateCode(3);
  cout << "\nEnter investment name: ";
  getline(cin, investment.name);
  cout << "Enter investment type (0 for cryptocurrency, 1 for stock): ";
  int type;
  cin >> type;
  cin.ignore();
  investment.type = static_cast<InvestmentType>(type);
  cout << "Enter purchase price: ";
  cin >> investment.purchasePrice;
  cout << "Enter current value: ";
  cin >> investment.currentValue;
  cout << "Enter quantity: ";
  cin >> investment.quantity;

  InvestmentNode *newNode = createInvestmentNode(investment);
  if (portfolio->head == nullptr)
  {
    portfolio->head = newNode;
    portfolio->tail = newNode;
  }
  else
  {
    portfolio->tail->next = newNode;
    newNode->prev = portfolio->tail;
    portfolio->tail = newNode;
  }

  cout << "New investment added to portfolio " << portfolio->name << ".\n";
}

void updateInvestment(vector<Portfolio> &portfolios)
{
  string portfolioCode;
  cout << "\nEnter the code of the portfolio containing the investment to update: ";
  getline(cin, portfolioCode);

  Portfolio *portfolio = findPortfolioByCode(portfolios, portfolioCode);
  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << portfolioCode << " not found.\n";
    return;
  }

  string investmentCode;
  cout << "\nEnter the code of the investment to update: ";
  getline(cin, investmentCode);

  InvestmentNode *current = portfolio->head;
  while (current != nullptr)
  {
    if (current->data.code == investmentCode)
    {
      cout << "Enter updated current value: ";
      cin >> current->data.currentValue;
      cout << "Investment updated.\n";
      return;
    }
    current = current->next;
  }
  cout << "Investment with code " << investmentCode << " not found.\n";
}

void deleteInvestment(vector<Portfolio> &portfolios)
{
  string portfolioCode;
  cout << "Enter the code of the portfolio containing the investment to delete: ";
  getline(cin, portfolioCode);

  Portfolio *portfolio = findPortfolioByCode(portfolios, portfolioCode);
  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << portfolioCode << " not found.\n";
    return;
  }

  string investmentCode;
  cout << "\nEnter the code of the investment to delete: ";
  getline(cin, investmentCode);

  InvestmentNode *current = portfolio->head;
  while (current != nullptr)
  {
    if (current->data.code == investmentCode)
    {
      if (current->prev != nullptr)
      {
        current->prev->next = current->next;
      }
      else
      {
        portfolio->head = current->next;
      }
      if (current->next != nullptr)
      {
        current->next->prev = current->prev;
      }
      else
      {
        portfolio->tail = current->prev;
      }

      delete current;
      cout << "\nInvestment with code " << investmentCode << " deleted from portfolio " << portfolio->name << ".\n";
      return;
    }
    current = current->next;
  }
  cout << "\nInvestment with code " << investmentCode << " not found in portfolio " << portfolio->name << ".\n";
}

void calculateReturnOnInvestment(vector<Portfolio> &portfolios)
{
  string portfolioCode;
  cout << "Enter the code of the portfolio to calculate ROI: ";
  getline(cin, portfolioCode);

  Portfolio *portfolio = findPortfolioByCode(portfolios, portfolioCode);

  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << portfolioCode << " not found.\n";
    return;
  }

  if (portfolio->head == nullptr)
  {
    cout << "\nPortfolio " << portfolio->name << " does not contain any investments.\n";
    return;
  }

  LinkedListNode *totalInvestmentHead = nullptr;
  LinkedListNode *totalCurrentValueHead = nullptr;

  InvestmentNode *current = portfolio->head;
  while (current != nullptr)
  {
    double investment = current->data.purchasePrice * current->data.quantity;
    double currentValue = current->data.currentValue * current->data.quantity;

    appendToList(totalInvestmentHead, investment);
    appendToList(totalCurrentValueHead, currentValue);

    current = current->next;
  }

  double totalInvestment = calculateTotalFromList(totalInvestmentHead);
  double totalCurrentValue = calculateTotalFromList(totalCurrentValueHead);

  double roi = ((totalCurrentValue - totalInvestment) / totalInvestment) * 100.0;

  cout << "\nTotal Return on Investment for portfolio " << portfolio->name << ": " << roi << "%\n";
}
