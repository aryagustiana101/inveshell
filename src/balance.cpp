#include <string>
#include <sstream>
#include <iostream>
#include "headers/data.h"
#include "headers/utils.h"

void displayBalance(Account *account)
{
  cout << "\nCurrent Account Balance: " << account->balance << "\n";
}

void incrementBalance(Account *account)
{
  int amount;
  string input;

  cout << "\nEnter amount to increment account balance: ";
  getline(cin, input);

  if (!isValidNumber(input))
  {
    cout << "\nInvalid input. Please enter a valid number.\n";
    return;
  }

  stringstream(input) >> amount;

  account->balance += amount;

  cout << "\nAccount balance incremented by " << amount;
  cout << "\nNew balance: " << account->balance << "\n";
}

void decrementBalance(Account *account)
{
  int amount;
  string input;

  cout << "\nEnter amount to decrement account balance: ";
  getline(cin, input);

  if (!isValidNumber(input))
  {
    cout << "\nInvalid input. Please enter a valid number.\n";
    return;
  }

  stringstream(input) >> amount;

  if (account->balance - amount < 0)
  {
    cout << "\nDecrementing by " << amount << " would result in negative account balance. Operation aborted.\n";
    return;
  }

  account->balance -= amount;

  cout << "\nAccount balance decremented by " << amount;
  cout << "\nNew balance: " << account->balance << "\n";
}