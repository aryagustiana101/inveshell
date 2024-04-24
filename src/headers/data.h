#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

enum InvestmentType
{
  CRYPTOCURRENCY,
  STOCK
};

struct Investment
{
  int code;
  string name;
  InvestmentType type;
  int purchasePrice;
  int currentValue;
  int quantity;
};

struct Portfolio
{
  string code;
  string name;
  vector<Investment> investments;
};

#endif
