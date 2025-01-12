#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
 srand(time(0));	
 int random = rand() % 21;
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
         if(response > random) {
             cout << "Arvauksesi oli " << response-random << " suurempi" << endl;
         }
     }
     return 0;
}
