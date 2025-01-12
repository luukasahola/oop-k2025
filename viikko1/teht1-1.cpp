#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
 int random = rand() % 21;
 srand(time(0));
 int response;

 cout << "Arvaa numero välillä 1-20" << endl;

     while(response != random) {
         cin >> response;


         if(response < random) {
             cout << "Arvauksesi oli " << random-response << " pienempi" << endl;
         }
         if(response == random) {
             cout << "Onnittelut, " << response << " oli oikea vastaus!" << endl;
             break;
         }
         else {
             cout << "Arvauksesi oli " << response-random << " suurempi" << endl;
         }
     }
     return 0;
}
