#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H


#include "chef.h"

using namespace std;

class ItalianChef :public Chef
{
public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string,int,int);
private:
    int makePizza(int,int);
    int flour;
    int water;
    string password = "pizza";
};

#endif // ITALIANCHEF_H
