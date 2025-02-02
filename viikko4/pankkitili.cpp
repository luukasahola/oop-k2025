#include "pankkitili.h"

Pankkitili::Pankkitili(string s)
{
    s = omistaja;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double a)
{
    saldo = saldo + a;
    return true;
}

bool Pankkitili::withdraw(double a)
{
    if(saldo - a >= 0)
    {
        saldo = saldo - a;
        return true;
    }
    else
    {
        cout << "Withdrawals resulting in negative account balances are not allowed." << endl;
        return false;
    }
}
