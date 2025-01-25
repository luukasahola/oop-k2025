#include "chef.h"

Chef::Chef(string s)
{
   Chef::chefName = s;
    cout << "Chef " << Chef::getName() << " constructor"<< endl;
}

Chef::~Chef()
{
    cout << "Chef " << Chef::getName() << " destructor"<< endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int a)
{
    cout << "Chef " << Chef::getName() << " with " << a << " items can make salad " << a/5 << " portions." << endl;
}

int Chef::makeSoup(int a)
{
    cout << "Chef " << Chef::getName() << " with " << a << " items can make soup " << a/3 << " portions." << endl;
}
