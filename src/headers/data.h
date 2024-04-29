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
  string code;
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

struct LinkedListNode
{
  double data;
  LinkedListNode *next;

  LinkedListNode(double val) : data(val), next(nullptr) {}
};

#endif
