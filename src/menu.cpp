#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/portfolio.h"

using namespace std;

void managePortfolioMenu(vector<Portfolio> &portfolios)
{
  int choice;

  do
  {
    string _choice;

    cout << "\nPortfolio Management Menu:\n";
    cout << "1. Display All Portfolios\n";
    cout << "2. Select Portfolio\n";
    cout << "3. Create Portfolio\n";
    cout << "4. Back to Main Menu\n";
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
      break;
    }
    case 2:
    {
      break;
    }
    case 3:
    {
      string code, name;
      cout << "\nEnter portfolio code: ";
      getline(cin, code);
      cout << "Enter portfolio name: ";
      getline(cin, name);
      portfolios.push_back(createPortfolio(code, name));
      cout << "\nNew portfolio created.\n";
      break;
    }
    case 4:
      cout << "\nReturning to main menu.\n";
      return;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 4.\n";
    }
  } while (choice != 4);
}

void mainMenu()
{
  int choice;
  vector<Portfolio> portfolios;

  do
  {
    string _choice;

    cout << "\nMain Menu:\n";
    cout << "1. Manage Portfolio\n";
    cout << "2. Calculate Return on Investment\n";
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
      managePortfolioMenu(portfolios);
      break;
    case 2:
      break;
    case 3:
      cout << "\nExiting Inveshell. Goodbye!\n\n";
      break;
    default:
      cout << "\nInvalid choice. Please enter a number from 1 to 3.\n";
    }
  } while (choice != 3);
}