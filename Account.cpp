#include "Account.h"

using namespace std;
Account::Account(){
	numAcc = countacc();
	id = 0;
	pin = 0;
	wrongtimes = 0;
	balance = 0;
}
int Account::getcountacc()
{
    return numAcc;
}
int Account::get_PIN()
{
    return pin;
}
int Account::get_wrongtimes()
{
    return wrongtimes;
}
int Account::get_balance()
{
    return balance;
}
int Account::get_ID()
{
    return id;
}
void Account::set_balance(int i)
{
    balance = data[i];
}
void Account::set_ID(int i)
{
    id = data[i];
}
void Account::set_pin(int i)
{
    pin = data[i];
}
void Account::set_wrongtimes(int i)
{
    wrongtimes = data[i];
}
void Account::set_data(int i,int j)
{
    data[i] = j;
}
void Account::set_numAcc(int i)
{
    numAcc = i;
}
int Account::countacc(){
	ifstream file;
	file.open("Account.txt");
	int i=0;
	while(!file.eof())
	{
		file >> data[i];
		i++;
	}
	file.close();
	int numacc = i/4;
	return numacc;
}
int Account::pincheck(int ID, int PIN)
{
    if (get_PIN() == PIN && get_ID() == ID && wrongtimes >= 5)
    {
        return 1;
    }
	if (get_PIN() == PIN && get_ID() == ID && wrongtimes < 5)
    {
        fstream file;
		file.open("Account.txt");
        for (int j = 0; j< numAcc*4; j += 4)
		{
			if (data[j+1] == ID)
            {
                data[j] = 0;
                set_wrongtimes(j);
            }
		}
		for (int i = 0;i < numAcc*4; i++) file << data[i] << endl;
		file.close();
        return 0;
    }

	if (get_PIN()!= PIN && get_ID() == ID)
	{
		fstream file;
		file.open("Account.txt");
		int j = 0;
		for (j = 0; j< numAcc*4; j=j+4)
		{
			if (data[j+1] == ID)
				break;
		}
		data[j] += 1;
		set_wrongtimes(j);
		for (int i = 0;i < numAcc*4 ;i++) file << data[i] << endl;
		file.close();
		return 1;
	}
	return 2;
}
bool Account::balance_check(int cash, Account& u)
{
    Screen a;
    ATM_box b;
    if(balance < cash)
    {
        a.noti(5);
        system("cls");
        a.menu(u);
        return false;
    }
    if(b.box[6] < cash)
    {
        a.noti(6);
        system("cls");
        a.menu(u);
        return false;
    }
    return true;
}
void Account::M_register()
{
    Screen s;
    int ID,PIN;
    fstream file;
    file.open("Account.txt");
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++" <<endl<<endl;
	cout<<"                 ____________________________________________"<<endl;
	cout<<"                |   Xin chao ^^. Xin moi dang ky tai khoan  |"<<endl;
	cout<<"                |___________________________________________|"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |     Buoc 1. Nhap ID                       |"<<endl;
	cout<<"                |     Buoc 2. Nhap ma Pin                   |"<<endl;
	cout<<"                |     Buoc 3. Cho he thong kiem tra         |"<<endl;
	cout<<"                |     Buoc 4: Thuc hien giao dich           |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |___________________________________________|"<<endl<<endl<<endl;
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    here:
    system("cls");
    cout << "Nhap ID: ";
    cin >> ID;
    cout << "Nhap PIN: ";
    cin >> PIN;
    for(int i =0; i < numAcc*4; i+=4)
    {
        if(data[i+1] == ID)
        {
            cout << "Dang ky khong thanh cong, tai khoan da ton tai, hay thu nhap ID khac ^^!"<<endl;
            Sleep(2000);
            goto here;
        }
    }
    cout << "Dang ky thanh cong!!, ban co the dang nhap ngay ^^";
    Sleep(2000);
    data[numAcc*4] = 0;
    data[numAcc*4+1] = ID;
    data[numAcc*4+2] = PIN;
    data[numAcc*4+3] = 0;
    for(int i = 0;i <(numAcc+1)*4 ;i++) file << data[i] << endl;
    file.close();
    s.StartScreen();

}
void Account::change_pincode()
{
    int old,new_pin;
    Screen s;
    here:
    cout << "Nhap mat khau hien tai: ";
    cin >> old;
    if(old == pin)
    {
        int i;
        fstream file;
        file.open("Account.txt");
        for(i =0; i < numAcc*4; i++)
        {
            if(id == data[i])
                break;
        }
        cout << "Nhap mat khau moi: ";
        cin >> new_pin;
        data[i+1] = new_pin;
        set_pin(i+1);
        for(i = 0; i < numAcc*4; i++)
            file << data[i] << endl;
        file.close();
        cout << "Doi mat khau thanh cong! Hay dang nhap lai";
        s.StartScreen();
    }
    else
    {
        cout << "Ban nhap sai mat khau hien tai, hay thu lai!" << endl;
        goto here;
    }
}
void Account::see_balance()
{
    InputKey x;
    Screen s;
    cout << "So du cua tai khoan " << id << " la " << balance<< endl;
    cout << "Bam 1 de tiep tuc giao dich, bam 0 de thoat ^^!"<<endl;
    if(x.gettheKey() == 1)
    {
        system("cls");
        s.menu(*this);
    }
}
void setdata(Account &num_of_acc, Account uzer[])
{
	int j = 0;
	for (int i=0;i<num_of_acc.countacc();i++)
	{
		uzer[i].set_wrongtimes(j);
		uzer[i].set_ID(j+1);
		uzer[i].set_pin(j+2);
		uzer[i].set_balance(j+3);
		j += 4;
	}
}
