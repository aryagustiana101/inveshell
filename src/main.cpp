#include <string>
#include <sstream>
#include <iostream>
#include "headers/menu.h"
#include "headers/banner.h"

using namespace std;

int main()
{
  banner();

  cout << "\nWelcome to Inveshell - Portfolio Investment Management App\n";

  mainMenu();

  return 0;
}