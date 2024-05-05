#ifndef AUTH_H
#define AUTH_H

#include <string>
#include "data.h"

using namespace std;

Account *signIn(vector<Account> &accounts);
void signUp(vector<Account> &accounts);

#endif
