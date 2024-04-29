#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

string generateCode(int length);
void appendToList(LinkedListNode *&head, double val);
void deleteList(LinkedListNode *&head);
double calculateTotalFromList(const LinkedListNode *head);

#endif
