#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/auth.h"
#include "headers/portfolio.h"
#include "headers/investment.h"

using namespace std;

void managePortfolioMenu(vector<Portfolio> &portfolios)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nPortfolio Management Menu:\n";
    cout << "1. Display All Portfolios\n";
    cout << "2. Create Portfolio\n";
    cout << "3. Update Portfolio\n";
    cout << "4. Delete Portfolio\n";
    cout << "5. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);
    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      displayAllPortfolios(portfolios);
      break;
    }
    case 2:
    {
      createPortfolio(portfolios);
      break;
    }
    case 3:
    {
      updatePortfolio(portfolios);
      break;
    }
    case 4:
    {
      deletePortfolio(portfolios);
      break;
    }
    case 5:
      cout << "\nReturning to main menu.\n";
      return;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 5.\n";
    }
  } while (choice != 5);
}

void manageInvestmentMenu(vector<Portfolio> &portfolios)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nInvestment Management Menu:\n";
    cout << "1. Display All Investments\n";
    cout << "2. Create Investment\n";
    cout << "3. Update Investment\n";
    cout << "4. Delete Investment\n";
    cout << "5. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);
    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      displayAllInvestments(portfolios);
      break;
    }
    case 2:
    {
      createInvestment(portfolios);
      break;
    }
    case 3:
    {
      updateInvestment(portfolios);
      break;
    }
    case 4:
    {
      deleteInvestment(portfolios);
      break;
    }
    case 5:
      cout << "\nReturning to main menu.\n";
      return;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 5.\n";
    }
  } while (choice != 5);
}

void mainMenu(Account *account)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nMain Menu:\n";
    cout << "1. Manage Portfolio\n";
    cout << "2. Manage Investment\n";
    cout << "3. Calculate Return on Investment\n";
    cout << "4. Sign out\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);

    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
      managePortfolioMenu(account->portfolios);
      break;
    case 2:
      manageInvestmentMenu(account->portfolios);
      break;
    case 3:
      calculateReturnOnInvestment(account->portfolios);
      break;
    case 4:
      cout << "\nSign out successful.\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 4.\n";
    }
  } while (choice != 4);
}

void authMenu(vector<Account> &accounts)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nAuth Menu:\n";
    cout << "1. Sign In\n";
    cout << "2. Sign Up\n";
    cout << "3. Exit\n";
    cout << "\nEnter your choice: ";
    getline(cin, _choice);

    stringstream ss(_choice);

    if (!(ss >> choice))
    {
      cout << "\nInvalid input. Please enter a number.\n";
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      Account *account = signIn(accounts);
      if (account != nullptr)
      {
        mainMenu(account);
      }
      break;
    }
    case 2:
      signUp(accounts);
      break;
    case 3:
      cout << "\nExiting Inveshell. Goodbye!\n\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 4.\n";
    }
  } while (choice != 3);
}