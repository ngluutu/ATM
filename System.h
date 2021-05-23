#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <fstream>
#include "Account.h"
#include "Trader.h"

class Account;
class Screen
{
	public:
		Screen();
		void StartScreen();
		void menu(Account);
		void noti(int);

};

class InputKey
{
	public:
        InputKey();
		int gettheKey();
		int getID();
		int getPIN();
		int choose();
};

class Card
{
    public:
        Card();
        int Read_card();

};


#endif // SYSTEM_H_INCLUDED
