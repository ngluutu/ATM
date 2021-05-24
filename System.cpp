#include "System.h"

using namespace std;
Screen::Screen(){}
void Screen::StartScreen()
{
    Account z;
    ATM_function a;
    ATM_box b;
    int x;
	InputKey y;
	here:
	system("cls");
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++" <<endl<<endl;
	cout<<"                 ____________________________________________"<<endl;
	cout<<"                |                 Mo ta                     |"<<endl;
	cout<<"                |___________________________________________|"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |     De bat dau giao dich hay dang nhap    |"<<endl;
	cout<<"                |     Neu ban da co tai khoan               |"<<endl;
	cout<<"                |     Bam 1 de dang nhap!                   |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |     Neu ban van chua co tai khoan.        |"<<endl;
	cout<<"                |     Bam 2 de dang ky!!                    |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |     De kiem tra tinh trang cay ATM        |"<<endl;
	cout<<"                |     Bam 3 !                               |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |     Neu ban da hoan thanh giao dich       |"<<endl;
	cout<<"                |     Bam 0 de thoat!                       |"<<endl;
	cout<<"                |___________________________________________|"<<endl<<endl<<endl;
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	x = y.gettheKey();
    system("cls");
	if(x == 1)
    {
        Card m;
        int n = m.Read_card();
        if(n == 3)
        {
            noti(3);
            a.logout();
        }
        if(n == 4)
        {
            noti(4);
            a.logout();
        }
	}
	if(x == 2)
    {
        z.M_register();
    }
    if(x == 3)
    {
        b.check_box();
    }
    if(x == 0)
    {
        exit(0);
    }
    else
    {
        noti(7);
        goto here;
    }
}
void Screen::menu(Account u)
{
    InputKey a;
    ATM_function y;
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++" <<endl;
	cout<<"                |Xin chao nguoi dung ^^. Hay nhap lua chon  |"<<endl;
	cout<<"                |___________________________________________|"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |      1. Nap tien                          |"<<endl;
	cout<<"                |      2. Rut tien                          |"<<endl;
	cout<<"                |      3. Chuyen tien den ID                |"<<endl;
	cout<<"                |      4. Kiem tra so du                    |"<<endl;
	cout<<"                |      5. Doi ma PIN                        |"<<endl;
	cout<<"                |      6. Dang xuat                         |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |___________________________________________|"<<endl<<endl<<endl;
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	here:
    int x = a.gettheKey();
    if(x == 1)
    {
        y.deposit(u);
    }
    if(x == 2)
    {
        y.withdraw(u);
    }
    if(x == 3)
    {
        y.transfer(u);
    }
    if(x == 4)
    {
        u.see_balance();
    }
    if(x == 5)
    {
        u.change_pincode();
    }
    if(x == 6)
    {
        y.logout();
    }
    else
    {
        noti(7);
        goto here;
    }
}
void Screen::noti(int i)
{
    switch(i)
    {
        case 2:
            cout << "Ban da nhap sai pin :( hay thu lai."<<endl;
            Sleep(500);
            break;
        case 3:
            cout << "Tai khoan cua ban da bi khoa vinh vien @@" <<endl;
            Sleep(2000);
            break;
        case 4:
            cout << "Khong co du lieu ve tai khoan nay, hay dang ky!"<<endl;
            Sleep(2000);
            break;
        case 5:
            cout << "So du tai khoan cua ban khong du de thuc hien giao dich. Hay nap them tien vao tai khoan ^^"<<endl;
            Sleep(2000);
            break;
        case 6:
            cout << "ATM khong con du tien de rut. Hay quay lai sau"<<endl;
            Sleep(2000);
            break;
        case 7:
            cout << "Lenh khong hop le, hay thu lai" << endl;
            Sleep(1000);
            break;

    }
}

InputKey::InputKey(){};
int InputKey::gettheKey()
{
	int x;
	cin >> x;
	return x;
}
int InputKey::getID()
{
    int ID;
    cout <<"Vui long nhap so ID cua ban: ";
    cin >> ID;
    return ID;
}
int InputKey::getPIN()
{
    int Pin;
    cout << "Vui long nhap ma pin: ";
    cin >> Pin;
    return Pin;
}
int InputKey::choose()
{
    int option;
    cout  << "Nhap lua chon cua ban: ";
    cin >> option;
    return option;
}

Card::Card(){};
int Card::Read_card()
{
    system("cls");
	Screen a;
	InputKey b;
	int _ID, _pin;
	int check;
	Account *uzer, num_of_acc;
	int acc = num_of_acc.countacc();
	uzer = new Account[acc];
	_ID = b.getID();
	here:
	_pin = b.getPIN();
	setdata(num_of_acc,uzer);
	for (int i = 0;i < acc ;i++)
	{
		check = uzer[i].pincheck(_ID,_pin);
		if(check == 0)
		{
			if (uzer[i].get_wrongtimes() < 5)
			{
				cout << "Dang nhap thanh cong ^^.";
				Sleep(2000);
				system("cls");
				a.menu(uzer[i]);
				return 1;
			}
			else
				return 3;
		}
		if (check == 1)
		{
			if (uzer[i].get_wrongtimes()<5)
            {
                a.noti(2);
                goto here;
            }
			else
				if (uzer[i].get_wrongtimes()>=5)
					return 3;
		}
	}
	return 4;
}
