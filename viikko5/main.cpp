#include <iostream>
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");
    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();
    n.poista(&b);
    n.tulosta();
    n.postita("Viesti1");
    return 0;
}
