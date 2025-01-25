#include <iostream>
#include <italianchef.h>

using namespace std;

int main()
{
    string s;
    Chef chef1("Gordon");
    ItalianChef ita1("Mario");
    chef1.makeSalad(47);
    chef1.makeSoup(60);
    cout << "Enter the password: ";
    cin >> s;
    ita1.askSecret(s, 33, 15);
    return 0;
}
