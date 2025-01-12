#include <iostream>
#include <cstdlib>

using namespace std;

int game(int maxnum) {
    srand(time(0));	
    int random = rand() % num+1;
    int response;
    int counter;

    cout << "Arvaa numero välillä 1-" << num << endl;

        while(response != random) {
            cin >> response;


            if(response < random) {
                cout << "Arvauksesi oli " << random-response << " pienempi" << endl;
                counter++;
            }
            if(response == random) {
                cout << "Onnittelut, " << response << " oli oikea vastaus!" << endl;
                counter++;
                break;
            }
            if(response > random) {
                cout << "Arvauksesi oli " << response-random << " suurempi" << endl;
                counter++;
            }

        }
       return counter;
}

int main()
{
    int result = game(39);
    cout << "Arvauksiesi määrä oli " << result << endl;
     return 0;
}
