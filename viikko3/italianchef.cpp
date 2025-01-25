#include "italianchef.h"


ItalianChef::ItalianChef(string str):Chef(0)
{
    ItalianChef::chefName = str;
    cout << "ItalianChef " << ItalianChef::getName() << " constructor"<< endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef" << ItalianChef::getName() << " destructor"<< endl;
}

bool ItalianChef::askSecret(string s, int a, int b)
{
cout << "Anna salasana: " << endl;
    switch(password.compare(s))
    {;
    case 0:
        cout << "Wrong password. Re-enter the password: ";
        cin >> s;
    default:
        cout << "Password correct. Forwarding info to ItalianChef" << ItalianChef::getName() << endl;
        makePizza(a,b);
        break;
    }
}

int ItalianChef::makePizza(int a, int b)
{
cout << "ItalianChef " << ItalianChef::getName() << " with " << a << " flour and " << b << " water " << " can make " << min(a,b)/5 << " pizzas." << endl;
}
