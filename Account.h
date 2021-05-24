#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "System.h"


class Account
{
    public:
       Account();
	   long data[1000];
	   int numAcc;
	   int countacc();
	   int getcountacc();
	   int get_ID();
	   int get_PIN();
	   int pincheck(int, int);
	   int get_balance();
	   int get_wrongtimes();
	   void set_ID(int);
	   void set_pin(int);
	   void set_wrongtimes(int);
	   void set_numAcc(int);
	   void set_balance(int);
	   void set_data(int, int);
	   void update(int, int);
	   void M_register();
	   void see_balance();
	   void change_pincode();
	   bool balance_check(int, Account&);


    private:
		int pin, id, wrongtimes;
		long long balance;
};

void setdata(Account&, Account[]);


#endif // ACCOUNT_H_INCLUDED
