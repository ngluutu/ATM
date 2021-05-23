#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include "System.h"


using namespace std;

class Account;
class ATM_function
{
    public:
        ATM_function();
        void withdraw(Account);
        void deposit(Account);
        void transfer(Account);
        void logout();
};

class ATM_box
{
    public:
        ATM_box();
        int m10,m20,m50,m100,m200,m500;
        long long box[7];
        void update_box(ATM_box& );
        void check_box();
};


#endif // TRADER_H_INCLUDED
