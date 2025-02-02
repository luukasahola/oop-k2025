#include "luottotili.h"

Luottotili::Luottotili(string s, double a) : Pankkitili(s)
{
    if(a > 0)
    {
    luottoRaja = a;
    }
    else
    {
        cout << "Credit limit cannot be negative" << endl;
    }
}

bool Luottotili::deposit(double a)
{
    if(saldo+a <= 0)
    {
        saldo = saldo+a;
        return true;
    }
    else
    {
        cout << "Deposits resulting in larger balance than the credit limit are not allowed." << endl;
        return false;
    }
}

bool Luottotili::withdraw(double a)
{
    if((saldo-a)+luottoRaja >= 0)
    {
        saldo = saldo-a;
        return true;
    }
    else
    {
        cout << "Credit withdrawals resulting in larger credit balance than credit limit are not allowed." << endl;
        return false;
    }
}
