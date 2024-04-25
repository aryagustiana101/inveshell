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

struct InvestmentNode
{
  Investment data;
  InvestmentNode *next;
  InvestmentNode *prev;
};

struct Portfolio
{
  string code;
  string name;
  InvestmentNode *head;
  InvestmentNode *tail;
};

#endif
