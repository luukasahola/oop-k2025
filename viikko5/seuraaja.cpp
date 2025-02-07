#include "seuraaja.h"

Seuraaja::Seuraaja(string s)
{
cout << "Luodaan seuraaja " << s << endl;
nimi = s;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string s)
{
cout << "Seuraaja " << getNimi() << " sai viestin " << s << endl;
}
