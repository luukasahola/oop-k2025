#ifndef CHEF_H
#define CHEF_H
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Chef {
public:
    Chef(string);
    Chef(int) {}
    ~Chef();
    string getName();
    int makeSalad(int);
    int makeSoup(int);
private:

protected:
    string chefName;
};

#endif // CHEF_H
