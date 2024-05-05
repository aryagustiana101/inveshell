#ifndef MENU_H
#define MENU_H
#include <vector>
#include "data.h"

using namespace std;

void authMenu(vector<Account> &accounts);
void mainMenu(Account *account);
void managePortfolioMenu(vector<Portfolio> &portfolios);

#endif
