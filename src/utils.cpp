#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateCode(int length)
{
  const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string result;
  srand(time(nullptr));

  for (int i = 0; i < length; ++i)
  {
    int randomIndex = rand() % (sizeof(alphabet) - 1);
    result += *(alphabet + randomIndex);
  }

  return result;
}
