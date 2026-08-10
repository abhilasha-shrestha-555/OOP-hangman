#include <iostream>
#include <string>
using namespace std;

// Function to display the hangman
void drawHangman(int wrong) {
    cout << "\n";
    cout << "  |   |\n";

    if (wrong >= 1)
        cout << "  O   |\n";
    else
        cout << "      |\n";

    if (wrong == 2)
        cout << "  |   |\n";
    else if (wrong == 3)
        cout << " /|   |\n";
    else if (wrong >= 4)
        cout << " /|\\  |\n";
    else
        cout << "      |\n";

    if (wrong == 5)
        cout << " /    |\n";
    else if (wrong >= 6)
        cout << " / \\  |\n";
    else
        cout << "      |\n";

    cout << "      |\n";
    cout << "=========\n";
}

// Function to check if a letter is already guessed
bool alreadyGuessed(char letter, string guessed) {
    for (char c : guessed) {
        if (c == letter)
            return true;
    }
    return false;
}

int main() {

    string word = "computer";
    string guessedWord = "________";
    string guessedLetters = "";

    int wrong = 0;
    const int maxWrong = 6;

    cout << "      HANGMAN GAME\n";

    while (wrong < maxWrong && guessedWord != word) {

        drawHangman(wrong);

        cout << "\nWord: ";
        for (char c : guessedWord)
            cout << c << " ";

        cout << "\nGuessed letters: " << guessedLetters;
        cout << "\nWrong guesses left: " << maxWrong - wrong;

        char guess;
        cout << "\n\nEnter a letter: ";
        cin >> guess;

        // Convert uppercase to lowercase
        if (guess >= 'A' && guess <= 'Z')
            guess = guess + 32;

        // Check if letter was already guessed
        if (alreadyGuessed(guess, guessedLetters)) {
            cout << "You already guessed that letter!\n";
            continue;
        }

        guessedLetters += guess;

        bool found = false;

        // Check the word
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (found) {
            cout << "Correct guess!\n";
        } else {
            cout << "Wrong guess!\n";
            wrong++;
        }
    }

    drawHangman(wrong);

    if (guessedWord == word) {
        cout << "\n🎉 YOU WIN!\n";
        cout << "The word was: " << word << endl;
    } else {
        cout << "\n💀 GAME OVER!\n";
        cout << "The word was: " << word << endl;
    }

    return 0;
}