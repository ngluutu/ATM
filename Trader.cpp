#include "Trader.h"
ATM_function::ATM_function(){}
void ATM_function::deposit(Account u)
{
    InputKey x;
    Screen s;
    ATM_box a;
    fstream file;
    file.open("Account.txt");
    int i;
    int k = u.countacc();
    for(i =0; i < k*4; i++)
    {
        if(u.get_ID() == u.data[i])
            break;
    }
    int currency;
    int amount;
    cout << "Nhap menh gia: ";
    cin >> currency;
    cout << "Nhap so to: ";
    cin >> amount;
    int cash = currency*amount;
    int z = u.data[i+2] + cash;
    u.set_data(i+2, z);
    u.set_balance(i+2);
    for(int j = 0; j < k*4; j++)
        file << u.data[j] << endl;
    file.close();
    file.open("ATM_box.txt");
    if(currency == 10000)
    {
        a.box[0] += amount;
    }
    if(currency == 20000)
    {
        a.box[1] += amount;
    }
    if(currency == 50000)
    {
        a.box[2] += amount;
    }
    if(currency == 100000)
    {
        a.box[3] += amount;
    }
    if(currency == 200000)
    {
        a.box[4] += amount;
    }
    if(currency == 500000)
    {
        a.box[5] += amount;
    }
    a.update_box(a);
    for(int i =0;i < 7; i++)
        file << a.box[i] << endl;
    file.close();
    cout << "Nap tien thanh cong ^^!" << endl;
    cout << "Bam 1 de tiep tuc giao dich, bam 0 de thoat ^^!"<<endl;
    file.open("History.txt",ios::app);
    file << "Tai khoan " << u.get_ID() << " da duoc nap " << cash << " dong!" << endl;
    file.close();
    if(x.gettheKey() == 1)
    {
        system("cls");
        s.menu(u);
    }
    else logout();
}
void ATM_function::withdraw(Account u)
{
    ATM_box a;
    Screen s;
    InputKey x;
    fstream file;
    file.open("Account.txt");
    int k = u.countacc();
    int i;
    int cash;
    for(i =0; i < k*4; i++)
    {
        if(u.get_ID() == u.data[i])
            break;
    }
    cout << "Hay nhap menh gia la boi so cua 10000 ^^!" << endl;
    cout << "Nhap so tien ban muon rut: ";
    cin >> cash;
    int temp = cash;
    if(u.balance_check(cash) == true)
    {
        u.data[i+2] -= cash;
        u.set_balance(i+2);
        if(cash / 500000 != 0 && cash/500000 <= a.box[5] )
        {
            cout << "Cay ATM dua ra " << cash/500000 << " to 500000" << endl;
            a.box[5] -= cash/500000;
            cash = cash - (cash/500000)*500000;
        }
        if(cash / 500000 != 0 && cash/500000 > a.box[5] && a.box[5] != 0 )
        {
            cout << "Cay ATM dua ra " << a.box[5] << " to 500000" << endl;
            cash = cash - (a.box[5])*500000;
            a.box[5] = 0;
        }

        if(cash / 200000 != 0 && cash/200000 <= a.box[4])
        {
            cout << "Cay ATM dua ra " << cash/200000 << " to 200000" << endl;
            a.box[4] -= cash/200000;
            cash = cash - (cash/200000)*200000;
        }
        if(cash / 200000 != 0 && cash/200000 > a.box[4] && a.box[4] != 0)
        {
            cout << "Cay ATM dua ra " << a.box[4] << " to 500000" << endl;
            cash = cash - (a.box[4])*200000;
            a.box[4] = 0;
        }

        if(cash/100000 != 0 && cash/100000 <= a.box[3])
        {
            cout << "Cay ATM dua ra " << cash/100000 << " to 100000" << endl;
            a.box[3] -= cash/100000;
            cash = cash - (cash/100000)*100000;
        }
        if(cash/100000 != 0 && cash/100000 > a.box[3] && a.box[3] != 0)
        {
            cout << "Cay ATM dua ra " << a.box[3] << " to 100000" << endl;
            cash = cash - (a.box[3])*100000;
            a.box[3] = 0;
        }

        if(cash / 50000 != 0 && cash/50000 <= a.box[2])
        {
            cout << "Cay ATM dua ra " << cash/50000 << " to 50000" << endl;
            a.box[2] -= cash/50000;
            cash = cash - (cash/50000)*50000;
        }
        if(cash / 50000 != 0 && cash/50000 > a.box[2] && a.box[2] != 0)
        {
            cout << "Cay ATM dua ra " << a.box[2] << " to 50000" << endl;
            cash = cash - (a.box[2])*50000;
            a.box[2] = 0;
        }

        if(cash / 20000 != 0 && cash/20000 <= a.box[1])
        {
            cout << "Cay ATM dua ra " << cash/20000 << " to 20000" << endl;
            a.box[1] -= cash/20000;
            cash = cash - (cash/20000)*20000;
        }
        if(cash / 20000 != 0 && cash/20000 > a.box[1]&& a.box[1] != 0)
        {
            cout << "Cay ATM dua ra " << a.box[1] << " to 20000" << endl;
            cash = cash - (a.box[1])*20000;
            a.box[1] = 0;
        }

        if(cash / 10000 != 0 && cash/10000 <= a.box[0])
        {
            cout << "Cay ATM dua ra " << cash/10000 << " to 10000" << endl;
            a.box[1] -= cash/10000;
            cash = cash - (cash/10000)*10000;
        }
        if(cash / 10000 != 0 && cash/10000 > a.box[0] && a.box[0] != 0)
        {
            cout << "Cay ATM dua ra " << a.box[0] << " to 10000" << endl;
            cash = cash - (a.box[0])*10000;
            a.box[1] = 0;
        }
        if(cash != 0)
        {
            u.data[i+2] += cash;
            cout << "Hien tai ATM khong du tien de rut het menh gia nay! Da hoan tra " << cash << " vao tai khoan." << endl;
        }
        u.set_balance(i+2);
        a.update_box(a);
        for(int i = 0; i < k*4; i++)
            file << u.data[i] << endl;
        file.close();
        file.open("ATM_box.txt");
        for(int i =0;i < 7; i++)
            file << a.box[i] << endl;
        file.close();
        file.open("History.txt",ios::app);
        file << "Tai khoan " << u.get_ID() << " da rut " << temp << " dong!" << endl;
        file.close();
        cout << "Bam 1 de tiep tuc giao dich, bam 0 de thoat ^^!"<<endl;
        if(x.gettheKey() == 1)
        {
            system("cls");
            s.menu(u);
        }
        else logout();
    }
}
void ATM_function::transfer(Account u)
{
    long amount;
    InputKey x;
    Screen s;
    fstream file;
    int ID;
    int k = u.countacc();
    int i;
    int j;
    file.open("Account.txt");
    here:
    cout << "Moi ban nhap ID nguoi nhan:";
    cin >> ID;
    for( i =0 ; i < k*4 ; i++)
    {
        if(u.get_ID() == u.data[i])
            break;
    }
    for(j = 0 ; j < k*4 ; j++)
    {
        if(u.data[j] == ID)
            break;
    }
    if(j == k*4)
    {
        cout << "ID ban nhap khong ton tai, hay kiem tra lai :("<<endl;
        goto here;
    }
    else
    {
        cout << "Nhap so tien ban muon gui:";
        cin >> amount;
        u.data[i+2] -= amount;
        u.data[j+2] += amount;
        cout << "Tai khoan " << u.get_ID() << " da chuyen tien cho tai khoan " << ID << " thanh cong ^^"<<endl;
        u.set_balance(i+2);
        for(int z = 0; z < k*4; z++)
            file << u.data[z] << endl;
        file.close();
        file.open("History.txt",ios::app);
        file << "Tai khoan " << u.get_ID() << " da chuyen " << amount << " dong cho tai khoan " << ID << "!" << endl;
        file.close();
        cout << "Bam 1 de tiep tuc giao dich, bam 0 de thoat ^^!"<<endl;
        if(x.gettheKey() == 1)
        {
            system("cls");
            s.menu(u);
        }
        else logout();
    }
}
void ATM_function::logout()
{
    Screen s;
    s.StartScreen();
}

ATM_box::ATM_box()
{
    fstream file;
    file.open("ATM_box.txt");
    for(int i =0; i < 7 ; i++)
        file >> box[i];
    m10 = box[0];
    m20 = box[1];
    m50 = box[2];
    m100 = box[3];
    m200 = box[4];
    m500 = box[5];
    box[6] = box[0]*10000+box[1]*20000+box[2]*50000+box[3]*100000+box[4]*200000+box[5]*500000;
    file.close();
}
void ATM_box::update_box(ATM_box &b)
{
    b.box[6] = b.box[0]*10000+b.box[1]*20000+b.box[2]*50000+b.box[3]*100000+b.box[4]*200000+b.box[5]*500000;
}
void ATM_box::check_box()
{
    fstream file;
    InputKey x;
    Screen s;
    file.open("ATM_box.txt");
    for(int i =0; i < 7 ; i++)
        file >> box[i];
    cout<<"                +++++++++++++++++++++++++++++++++++++++++++++" <<endl;
	cout<<"                |Xin chao ^^. Day la tinh trang cua ATM     |"<<endl;
	cout<<"                |___________________________________________|"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |      1. So to menh gia 10000  :" << box[0] <<"         |"<<endl;
	cout<<"                |      2. So to menh gia 20000  :" << box[1] <<"         |"<<endl;
	cout<<"                |      3. So to menh gia 50000  :" << box[2] <<"         |"<<endl;
	cout<<"                |      4. So to menh gia 100000 :" << box[3] <<"         |"<<endl;
	cout<<"                |      5. So to menh gia 200000 :" << box[4] <<"         |"<<endl;
	cout<<"                |      6. So to menh gia 500000 :" << box[5] <<"         |"<<endl;
	cout<<"                |      7. Tong so tien trong ATM:" << box[6] <<"   |"<<endl;
	cout<<"                |                                           |"<<endl;
	cout<<"                |___________________________________________|"<<endl<<endl<<endl;
	cout<<"                +++++++++++++++++++++++++++++++++++++++++++++"<<endl<<endl<<endl;
    file.close();
    cout << "Bam 1 de dang nhap, bam 0 de thoat ^^!"<<endl;
    if(x.gettheKey() == 1)
    {
        s.StartScreen();
    }

}
