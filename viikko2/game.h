#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Game 
{

public:
    Game(int);
    ~Game();
    void play();
private:
    void printGameResult();
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

};

Game::Game(int a) 
{
    srand(time(0));
    maxNumber = a;
    randomNumber = rand() % maxNumber+1;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as initial value" << endl;
}

Game::~Game() 
{
    printGameResult();
    cout << "GAME DESTRUCTOR: Object cleared from stack memory" << endl;
}

void Game::play() 
{
    cout << "Arvaa numero välillä " << 0 << " ja " << maxNumber << "." << endl;
    cin >> playerGuess; // Käyttäjän arvaus suoraan funktioon

    while(randomNumber != playerGuess) 
    {
        if(randomNumber > playerGuess) 
        {
            cout << "Arvauksesi oli " << randomNumber - playerGuess << " liian pieni" << endl;
            numOfGuesses++;
        }
        if(randomNumber < playerGuess) 
        {
            cout << "Arvauksesi oli " << playerGuess - randomNumber << " liian suuri" << endl;
            numOfGuesses++;
        }
        if(randomNumber == playerGuess) 
        {
            numOfGuesses++;
            break;
        }
        cin >> playerGuess;
    }

}

void Game::printGameResult() 
{
    cout << "Arvauksesi oli oikein! Oikea vastaus oli " << randomNumber << ". " << "Arvasit " <<  numOfGuesses << " kertaa." << endl;
}

#endif // GAME_H
