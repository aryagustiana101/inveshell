#include <string>
#include <iostream>
#include "headers/data.h"

using namespace std;

Account *signIn(vector<Account> &accounts)
{
  string username, pin;

  cout << "\nEnter username: ";
  getline(cin, username);
  cout << "Enter PIN: ";
  getline(cin, pin);

  for (auto &account : accounts)
  {
    if (account.username == username && account.pin == pin)
    {
      cout << "\nSign in successful.\n";
      return &account;
    }
  }
  cout << "\nInvalid username or PIN.\n";

  return nullptr;
}

void signUp(vector<Account> &accounts)
{
  string username, pin;

  cout << "\nEnter new username: ";
  getline(cin, username);
  cout << "Enter new PIN: ";
  getline(cin, pin);

  for (const auto &account : accounts)
  {
    if (account.username == username)
    {
      cout << "\nUsername already exists. Please choose a different username.\n";
      return;
    }
  }

  Account account;
  account.username = username;
  account.pin = pin;
  account.balance = 0;
  accounts.push_back(account);

  cout << "\nAccount created successfully.\n";
}