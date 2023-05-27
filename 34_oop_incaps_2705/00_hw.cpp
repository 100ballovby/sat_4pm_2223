#include <iostream>
using namespace std;

class GuessTheNumberGame {
private:
    int random_number;  //
    int guesses = 0;  // количество попыток
    int retries = 8;
public:
    GuessTheNumberGame() {
        // Генерируем случайное число в диапазоне от 1 до 100
        random_number = rand() % 100 + 1;
    }

    void play() {
        int guess;
        char guessed = '-';
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        while (guess != random_number && guesses <= retries) {
            if (guess > random_number) {
                cout << "Your number is too high! Try again!" << endl;
            } else if (guess < random_number) {
                cout << "Your number is too low! Try again!" << endl;
            } else if (guess == random_number) {
                guessed = '+';
            }
            guesses++;

            cout << "Guess a number between 1 and 100: ";
            cin >> guess;
        }
        cout << "Guessed: " << guessed << endl;
        if (guessed == '+') {
            cout << "Sorry! Your attempts ended! The number was: " << random_number << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << guesses << " attempts!" << endl;
        }
    }
};

int hw_incaps_main() {
    srand(time(NULL));
    GuessTheNumberGame game;
    game.play();
    return 0;
}
