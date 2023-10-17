#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGame() {
    int minRange = 1;
    int maxRange = 100;
    int secretNumber = generateRandomNumber(minRange, maxRange);
    int attempts = 0;
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << minRange << " and " << maxRange << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number (" << secretNumber << ") in " << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);
}

int main() {
    srand(time(0)); 
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;

    return 0;
}
