#include <string>
#include <sstream>
#include <iostream>
#include "headers/data.h"

using namespace std;

Portfolio createPortfolio(string code, string name)
{
  Portfolio portfolio;
  portfolio.code = code;
  portfolio.name = name;
  portfolio.investments = {};
  return portfolio;
}