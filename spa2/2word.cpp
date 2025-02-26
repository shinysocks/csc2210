/*
 * Noah Dinan
 * SPA2 - Wordle Assist
 * https://faculty-web.msoe.edu/hasker/csc2210/as/2/
 */

#include "iostream"
using namespace std;

const int MAX_SIZE = 3000;
const int MAX_WORD_SIZE = 5;

void populate_words(string words[]) {
    string word;
    int i = 0;
    cin >> word;
    while (word != "END" && i < MAX_SIZE) {
        words[i] = word;
        cin >> word;
        i++;
    }
}

bool prune_word(string guess, string pattern, string word) {
    for (int i = 0; i < MAX_WORD_SIZE; i++) {

        switch (pattern[i]) {
            case '.':
                if (guess[i] != word[i]) return true; 
                break;
            case '?':
                if (word.find(guess[i]) == string::npos) return true;
                break;
            default:
                if (word.find(guess[i]) != string::npos) return true;
                break;
        }
    } return false;
}

void process_guesses(string guesses[], string words[], int size) {
    string pattern;
    int i = 0;
    while (cin) {
        cin >> guesses[i];
        cin >> pattern;

        for (int i = 0; i < size; i++) {
            if (prune_word(guesses[i], pattern, words[i])) {
                words[i] = "";
            } 
        }
        i++;
    }
}

int count(string strs[]) {
    int c = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        c += (strs[i] == "") ? 0 : 1;
    } return c;
}

int main() {
    string words[MAX_SIZE];
    string guesses[MAX_SIZE];
    populate_words(words);
    int words_size = count(words);
    process_guesses(guesses, words, words_size);
    int guess_size = count(guesses);
    words_size = count(words);

    cout << "Possible guesses after ";
    for (int i = 0; i < guess_size - 1; i++) {
        cout << guesses[i] + ", ";
    } cout << guesses[guess_size - 1] << ": " << words_size << endl;

    for (int i = 0; i < words_size; i++) {
        cout << words[i];
    }

    return 0;
}
