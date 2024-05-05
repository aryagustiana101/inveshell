#include <vector>
#include <iostream>
#include "headers/menu.h"
#include "headers/banner.h"

using namespace std;

int main()
{
  vector<Account> accounts;

  Account demoAccount;

  demoAccount.username = "demo";
  demoAccount.pin = "123";
  demoAccount.balance = 0;

  accounts.push_back(demoAccount);

  banner();

  cout << "\nWelcome to Inveshell - Portfolio Investment Management App\n";

  authMenu(accounts);

  return 0;
}
