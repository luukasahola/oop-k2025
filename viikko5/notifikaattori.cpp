#include "notifikaattori.h"


Notifikaattori::Notifikaattori()
{
cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *cur)
{
cout << "Lisää " << cur->getNimi() << endl;

if(seuraajat == nullptr)
{
    seuraajat = cur;
}
else
{
    cur->next = seuraajat;
    seuraajat = cur;
}
}

void Notifikaattori::poista(Seuraaja *b)
{
    Seuraaja * u = seuraajat;
    while(b != u->next)
    {
    cout << "Iterating " << u->getNimi() << endl;
    u->next = u;
    }
    cout << "Poistetaan " << b->getNimi() << endl;
    u->next = b->next;
}

void Notifikaattori::tulosta()
{
    Seuraaja *o = seuraajat;
    while(o != nullptr)
    {
        cout << "tulosta " << o->getNimi() << endl;
        o = o->next;
    }
}

void Notifikaattori::postita(string s)
{
Seuraaja *z = seuraajat;
cout << "Notifikaattori postaa viestin " << s << endl;
    while(z != nullptr)
    {
        z->paivitys(s);
        z = z->next;
    }
}
