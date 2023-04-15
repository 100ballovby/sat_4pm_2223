#include <iostream>
#include <ctime>

using namespace std;

struct RockPaperScissors {
private:
    int player_score;
    int computer_score;
    int rounds_played;

    // метод, который будет генерировать случайный выбор "фигуры"
    int computer_choice() {
        return rand() % 3;  // 0 - камень, 1 - ножницы, 2 - бумага
    }

    // метод, определяющий победителя в раунде игры
    int round_winner(int player_choice, int computer_choice) {
        if ((player_choice == 0 && computer_choice == 1) ||
            (player_choice == 1 && computer_choice == 2) ||
            (player_choice == 2 && computer_choice == 0)) {
            // игрок победил
            return 1;
        } else if ((player_choice == 1 && computer_choice == 0) ||
                   (player_choice == 2 && computer_choice == 1) ||
                   (player_choice == 0 && computer_choice == 2)) {
            // компьютер победил
            return 2;
        } else {
            // Ничья
            return 0;
        }
    }

    // Метод вывода сообщения о победителе
    void print_round_result(int winner, int player_choice, int computer_choice) {
        cout << "Your choice: ";
        switch (player_choice) {
            case 0:
                cout << "rock";
                break;
            case 1:
                cout << "scissors";
                break;
            case 2:
                cout << "paper";
                break;
        }
        cout << ", computer choice: ";
        switch (computer_choice) {
            case 0:
                cout << "rock";
                break;
            case 1:
                cout << "scissors";
                break;
            case 2:
                cout << "paper";
                break;
        }
        cout << ". ";
        if (winner == 1) {
            cout << "You win!";
            this->player_score++;
        } else if (winner == 2) {
            cout << "Computer wins!";
            this->computer_score++;
        } else {
            cout << "Nobody wins!";
        }
        cout << endl << endl;
    }

public:
    // конструктор для инициализации начальных значений
    RockPaperScissors() {
        player_score = 0;
        computer_score = 0;
        rounds_played = 0;
    }

    // метод игры
    void play() {
        while (true) {
            cout << "Insert your choice (0 - rock, 1 - scissors, 2 - paper): ";
            int player_choice;
            cin >> player_choice;
            while (player_choice < 0 || player_choice > 2) {
                cout << "Incorrect! insert 0, 1 or 2!";
                cin >> player_choice;
            }

            // выполнение раунда
            int comp_choice = computer_choice();
            int winner = round_winner(player_choice, comp_choice);
            print_round_result(winner, player_choice, comp_choice);
            rounds_played++;

            // проверка на завершение игры
            if (player_score >= 3) {
                cout << "You won! Congratulations🎉" << endl;
                break;
            } else if (computer_score >= 3) {
                cout << "Computer won! Looser!" << endl;
                break;
            }
        }
        // вывод статистики
        cout << "Game over! Stats: " << endl;
        cout << "Rounds played: " << rounds_played << endl;
        cout << "Player wins: " << player_score << " times." << endl;
        cout << "Computer wins: " << computer_score << " times." << endl << endl;

        rounds_played = 0;
        player_score = 0;
        computer_score = 0;
    }
};

int main() {
    srand(time(NULL));

    int play_again;
    RockPaperScissors game;
    do {
        game.play();
        cout << "Do you wanna play again? (1 - yes, 0 - no): ";
        cin >> play_again;
    } while (play_again != 0);

    cout << "Thank you!" << endl;
    return 0;
}