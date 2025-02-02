#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas a("aslak", 2500);
    Asiakas b("iisak", 400);
    a.getNimi(); // nimet esille
    b.getNimi();
    a.showSaldo(); // alkusaldot
    b.showSaldo();
    a.talletus(400);
    a.tiliSiirto(401,b); // tilisiirto suuremmalla summalla kuin a:n saldo
    a.showSaldo();
    b.showSaldo(); // saldot tilisiirtoyrityksen jälkeen
    b.talletus(50);
    b.nosto(49); // onnistunut nosto
    b.showSaldo(); // b:n saldo onnistuneen noston jälkeen
    a.luotonNosto(35);
    a.luotonMaksu(36); // epäonnistunut luotonmaksu
    a.showSaldo();
    b.nosto(1);
    a.tiliSiirto(400,b); // onnistunut viimeinen tilisiirto
    a.showSaldo(); // viimeiset saldot
    b.showSaldo();
    return 0;
}
