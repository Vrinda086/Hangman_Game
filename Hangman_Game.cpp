#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to choose a category
int chooseCategory() {
    int choice;
    cout << "Choose a category:" << endl;
    cout << "1. Animals" << endl;
    cout << "2. Flowers" << endl;
    cout << "3. Fruits" << endl;

    cout << "Enter your choice (1-3): ";
    cin >> choice;
    return choice;
}

// Function to choose a random word from the selected category
string getRandomWord(int category) {
    vector<string> animals = {"cat", "dog", "elephant", "tiger", "lion"};
    vector<string> flowers = {"daisy", "rose", "lily", "sunflower", "tulip"};
    vector<string> fruits = {"apple", "banana", "orange", "grape", "kiwi"};

    switch (category) {
        case 1:
            return animals[rand() % animals.size()]; 
        case 2:
            return flowers[rand() % flowers.size()];
        case 3:
            return fruits[rand() % fruits.size()];
        default:
            return ""; 
    }
    //Random word is chosen according to the category
}

// Function to display Hangman 
void displayHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
        case 0:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 1:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 2:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 3:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 4:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 5:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        case 6:
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << "=========" << endl;
            break;
        default:
            cout << "Unknown hangman state." << endl;
            break;
    }
}

// Function to play Hangman Game
void playHangman(const string& word) {
    int length = word.length();
    string guessed(length, '_');
    int attempts = 0;
    int inGuess = 0;
    bool guess = false;

    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word. It belongs to the selected category." << endl;

    while (!guess && attempts < 7) {
        cout << endl;
        displayHangman(inGuess);
        cout << "Word to guess: " << guessed << endl;
        cout << "Attempts remaining: " << 7 - attempts << endl;
        cout << "Enter a letter: ";
        char letter;
        cin >> letter;

        bool found = false;
        for (int i = 0; i < length; ++i) {
            if (word[i] == letter) {
                guessed[i] = letter;
                found = true;
            }
        }

        if (!found) {
            attempts++;
            inGuess++;
            cout << "Incorrect guess. Try again!" << endl;
        }

        if (guessed == word) {
            guess= true;
        }
    }

    cout << endl;
    if (guess) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        displayHangman(inGuess);
        cout << "Out of attempts! The word was: " << word << endl;
    }
}

int main() {
    srand(time(0)); 

    int categoryChoice = chooseCategory();
    string word = getRandomWord(categoryChoice);

    playHangman(word);

    return 0;
}

