#include "asiakas.h"


Asiakas::Asiakas(string s, double a):luottotili(s, a),kayttotili(s)
{
   cout << "Asiakas " << s << " initialized." << endl;
   nimi = s;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Asiakkaan " << nimi << " tilisaldo: "<< kayttotili.getBalance() << endl;
    cout << "Asiakkaan " << nimi << " luottovelka: " << -luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double a)
{
    if(a < 0)
    {
    cout << "Deposit too small. Please execute a deposit with a larger value." << endl;
    return false;
    }
    else
    {
        kayttotili.deposit(a);
        cout << nimi << " tallettaa " << a << " euroa " << " pankkitilille." << endl;
        return true;
    }
}

bool Asiakas::nosto(double a)
{
    if(a < 0)
    {
    cout << "Deposit too small. Please execute a deposit with a larger value." << endl;
    return false;
    }
    else if(kayttotili.withdraw(a) != true)
    {

    }
    else
    {

        //kayttotili.withdraw(a);
        cout << nimi << " nostaa " << a << " euroa " << " pankkitililtä." << endl;
        return true;
    }
}

bool Asiakas::luotonMaksu(double a)
{
    if(a < 0)
    {
    cout << "Deposit too small. Please execute a deposit with a larger value." << endl;
    return false;
    }
    else if(luottotili.deposit(a) != true)
    {

    }
    else
    {
        cout << nimi << " maksaa luottoa " << a << " euroa." << endl;
        return true;
    }
}


bool Asiakas::luotonNosto(double a)
{
    if(a < 0)
    {
        cout << "Credit withdrawal cannot be negative. Please execute a withdrawal with a positive value." << endl;
        return false;
    }
    else if(luottotili.withdraw(a) != true)
    {

    }
    else
    {
        cout << nimi << " nostaa luottoa " << a << " euroa." << endl;
        return true;
    }
}

bool Asiakas::tiliSiirto(double a, Asiakas &b)
{
    if(a < 0) {
        cout << "Transfer sum too small. Please try transferring a larger sum." << endl;
        return false;
    }
    else if(Asiakas::kayttotili.withdraw(a) != true)
    {

    }
    else
    {
        b.kayttotili.deposit(a);
        cout << nimi << " siirtää " << a << " euroa " << " asiakkaalle " << b.getNimi() << "." << endl;
        return true;
    }
}
