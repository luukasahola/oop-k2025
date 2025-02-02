#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Pankkitili
{
public:
    Pankkitili(string);
    virtual double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);
protected:
    string omistaja;
    double saldo = 0; // signed, täytyy toteuttaa negatiivisten arvojen kieltäminen ehtolauseilla
};

#endif // PANKKITILI_H
