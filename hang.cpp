#include <iostream>
#include <string>
using namespace std;

// ABSTRACTION 
class Game {
public:  
virtual void drawHangman(int wrong) = 0; // pure virtual function
};

// INHERITANCE
// HangmanGame inherits from Game
class HangmanGame : public Game {

private:
// ENCAPSULATION
string word;
string display;
char guess;
int attempts;
char correct;

public:
// CONSTRUCTOR
HangmanGame() {
word = "pink";
display = "____";
attempts = 5;
correct = false;
}

// POLYMORPHISM
// this function overrides the function from Game
void drawHangman(int wrong) override {
cout << "\n";
cout << "  -----\n";
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
if (wrong >= 5)
cout << " / \\  |\n";
else
cout << "      |\n";
cout << "      |\n";
}

// function to play the game
void playGame() {
cout << "\n";
cout << "    HANGMAN GAME\n";

while (attempts > 0) {

// to show the hangman
drawHangman(5 - attempts);

cout << "\nword: " << display << "\n";
cout << "enter a letter: ";
cin >> guess;

// to reset correct for every new guess
correct = false;

// to check the guessed letter
for (int i = 0; i < word.length(); i++) {

if (word[i] == guess) {
display[i] = guess;
correct = true;
}
}
if (correct) {
cout << "correct yayy!\n";
}
else {
cout << "wrong haha!\n";
attempts--;
cout << "attempts left: " << attempts << "\n";
}

// to check if the whole word has been guessed
if (word == display) {
cout << "\nYOU WON WOOHOO!!\n";
cout << "the word is: " << word << "\n";
return;
}
}

// final hangman
    drawHangman(5);
    cout << "\nGAME OVER LOSER BOO!\n";
    cout << "the word is: " << word << "\n";
}          
};  

// MAIN FUNCTION
int main() {

// to create an object
HangmanGame game;

// to start the game
game.playGame();
return 0;
}
