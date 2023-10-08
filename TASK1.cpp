#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!\n";
    
    do {
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts!\n";
        }
    } while (userGuess != randomNumber);

    return 0;
}