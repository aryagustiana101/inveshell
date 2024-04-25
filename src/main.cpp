#include <vector>
#include <iostream>
#include "headers/menu.h"
#include "headers/banner.h"

using namespace std;

int main()
{
  vector<Portfolio> portfolios;

  banner();

  cout << "\nWelcome to Inveshell - Portfolio Investment Management App\n";

  mainMenu(portfolios);

  return 0;
}
