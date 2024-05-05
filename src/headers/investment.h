#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
#include "data.h"

using namespace std;

void displayAllInvestments(vector<Portfolio> &portfolios);
void createInvestment(Account *account);
void updateInvestment(vector<Portfolio> &portfolios);
void deleteInvestment(vector<Portfolio> &portfolios);
void calculateReturnOnInvestment(vector<Portfolio> &portfolios);

#endif
