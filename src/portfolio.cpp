#include <string>
#include <iostream>
#include "headers/data.h"
#include "headers/utils.h"

using namespace std;

void displayAllPortfolios(const vector<Portfolio> &portfolios)
{
  cout << "\nAll Portfolios:\n";

  if (portfolios.size() == 0)
  {
    cout << "No Portfolios\n";
  }

  for (const Portfolio &portfolio : portfolios)
  {
    cout << "Code: " << portfolio.code << ", Name: " << portfolio.name << endl;
  }
}

Portfolio *findPortfolioByCode(vector<Portfolio> &portfolios, const string &code)
{
  for (Portfolio &portfolio : portfolios)
  {
    if (portfolio.code == code)
    {
      return &portfolio;
    }
  }

  return nullptr;
}

void createPortfolio(vector<Portfolio> &portfolios)
{
  Portfolio newPortfolio;
  newPortfolio.code = generateCode(6);
  cout << "\nEnter portfolio name: ";
  getline(cin, newPortfolio.name);
  newPortfolio.head = nullptr;
  newPortfolio.tail = nullptr;
  portfolios.push_back(newPortfolio);
  cout << "\nNew portfolio created.\n";
}

void updatePortfolio(vector<Portfolio> &portfolios)
{
  string code;
  cout << "\nEnter the code of the portfolio to update: ";
  getline(cin, code);

  Portfolio *portfolio = findPortfolioByCode(portfolios, code);
  if (portfolio == nullptr)
  {
    cout << "\nPortfolio with code " << code << " not found.\n";
    return;
  }

  string name;
  cout << "\nEnter new name for the portfolio: ";
  getline(cin, name);
  portfolio->name = name;
  cout << "\nPortfolio updated.\n";
}

void deletePortfolio(vector<Portfolio> &portfolios)
{
  string code;
  cout << "\nEnter the code of the portfolio to delete: ";
  getline(cin, code);

  auto it = portfolios.begin();
  while (it != portfolios.end())
  {
    if (it->code == code)
    {
      it = portfolios.erase(it);
      cout << "\nPortfolio deleted.\n";
      return;
    }
    else
    {
      ++it;
    }
  }
  cout << "\nPortfolio with code " << code << " not found.\n";
}