#include <iostream>
#include <cstdlib>
#include "game.h"

using namespace std;

int main()
{
    int a;

    cout << "Anna maksiminumero satunnaisnumerolle: " << endl;
    cin >> a;
    Game gameobj(a);
    gameobj.play();
    return 0;
}
