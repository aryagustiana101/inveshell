#ifndef MENU_H
#define MENU_H
#include <vector>
#include "data.h"

using namespace std;

void manageBalanceMenu(Account *account);
void managePortfolioMenu(vector<Portfolio> &portfolios);
void manageInvestmentMenu(Account *account);
void mainMenu(Account *account);
void authMenu(vector<Account> &accounts);

#endif
