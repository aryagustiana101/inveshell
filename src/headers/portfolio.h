#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include "data.h"

using namespace std;

void displayAllPortfolios(const vector<Portfolio> &portfolios);
Portfolio *findPortfolioByCode(vector<Portfolio> &portfolios, const string &code);
void createPortfolio(vector<Portfolio> &portfolios);
void updatePortfolio(vector<Portfolio> &portfolios);
void deletePortfolio(vector<Portfolio> &portfolios);

#endif
