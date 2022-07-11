#include <iostream>
#include<string.h>
using namespace std;

class Power
{
    public:
        void Bat_Nguon();
        void Tat_Nguon();
};

class OS
{
        char Ten[30];
    public:
        void Khoi_Dong();
        void Tat_HDH();
        friend class Computor;
};

class CPU
{
    Power Nguon;
    OS HDH;
    friend class Computor;
};

class Monitor
{
        int Do_Sang;
    public:
        void Dat_Do_Sang(int ds);
};

class Computor
{
        Monitor Man_Hinh;
        CPU Cpu;
    public:
        void Cai_Dat(char *tuple_element_t);
        void Bat_CPU();
        void Datdosang(int ds);
        void Tat_CPU();
};

void Power::Bat_Nguon()
{
    cout<<"\nNguon da bat";
}

void Power::Tat_Nguon()
{
    cout<<"\nNguon da tat";
}

void OS::Khoi_Dong()
{
    cout<<"\nHe dieu hanh da khoi dong: "<<Ten;
}

void OS::Tat_HDH()
{
    cout<<"\nDa tat he dieu hanh";
}

void Monitor::Dat_Do_Sang(int ds)
{
    Do_Sang=ds;
    cout<<"\nDo sang da duoc dat: "<<ds;
}

void Computor::Cai_Dat(char *ten)
{
    // strcpy(Cpu.HDH.Ten,ten);
    strcpy(Cpu.HDH.Ten, "WINXP");
}

void Computor::Bat_CPU()
{
    Cpu.Nguon.Bat_Nguon();
    Cpu.HDH.Khoi_Dong();
}

void Computor::Datdosang(int ds)
{
    Man_Hinh.Dat_Do_Sang(ds);
}

void Computor::Tat_CPU()
{
    Cpu.HDH.Tat_HDH();
    Cpu.Nguon.Tat_Nguon();
}

int main()
{
    system("cls");

    Computor c;

    c.Cai_Dat("WINXP");
    c.Bat_CPU();
    c.Datdosang(15);
    c.Tat_CPU();

    system("pause");
}