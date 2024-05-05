#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "headers/data.h"

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

void appendToList(LinkedListNode *&head, double val)
{
  LinkedListNode *newNode = new LinkedListNode(val);

  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    LinkedListNode *current = head;
    while (current->next != nullptr)
    {
      current = current->next;
    }
    current->next = newNode;
  }
}

double calculateTotalFromList(const LinkedListNode *head)
{
  double total = 0.0;
  const LinkedListNode *current = head;

  while (current != nullptr)
  {
    total += current->data;
    current = current->next;
  }

  return total;
}

void deleteList(LinkedListNode *&head)
{
  while (head != nullptr)
  {
    LinkedListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

bool isValidNumber(const string &str)
{
  stringstream ss(str);
  int num;
  ss >> noskipws >> num;

  return ss.eof() && !ss.fail() && num >= 0;
}