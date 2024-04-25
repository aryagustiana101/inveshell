#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
#include "data.h"

using namespace std;

void displayAllInvestments(vector<Portfolio> &portfolios);
void createInvestment(vector<Portfolio> &portfolios);
void updateInvestment(vector<Portfolio> &portfolios);
void deleteInvestment(vector<Portfolio> &portfolios);

#endif
