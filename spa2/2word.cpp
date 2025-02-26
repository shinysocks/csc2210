/*
 * Noah Dinan
 * SPA2 - Wordle Assist
 * https://faculty-web.msoe.edu/hasker/csc2210/as/2/
 */

#include "iostream"
using namespace std;

const int MAX_SIZE = 3000;
const int MAX_WORD_SIZE = 5;

int populate_words(string words[]) {
    string word;
    int i = 0;
    cin >> word;
    while (cin && word != "END" && i < MAX_SIZE) {
        words[i] = word;
        cin >> word;
        i++;
    }
    return i;
}

bool prune_word(string guess, string pattern, string word) {
    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        switch (pattern[i]) {
            case '.':
                if (guess[i] != word[i]) return true; 
                break;
            case '?':
                if (word[i] == guess[i] || word.find(guess[i]) == string::npos) return true;
                break;
            default:
                if (word.find(guess[i]) != string::npos) return true;
                break;
        }
    } return false;
}

int process_guesses(string guesses[], string words[], int size) {
    string pattern;
    int i = 0;
    cin >> guesses[i];
    cin >> pattern;

    if (!cin) return 1;

    while (cin) {
        for (int j = 0; j < size; j++) {
            if (words[j] != "" && guesses[i] != "" && prune_word(guesses[i], pattern, words[j])) {
                words[j] = "";
            }
        }

        i++;
        cin >> guesses[i];
        cin >> pattern;
    }
    return 0;
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
    int words_size = populate_words(words);
    int guess_size = 1;
    if (process_guesses(guesses, words, words_size) == 1) goto end;
    guess_size = count(guesses);
    words_size = count(words);

    end:
        cout << "Possible guesses after ";
        for (int i = 0; i < guess_size - 1; i++) {
            cout << guesses[i] + ", ";
        } cout << guesses[guess_size - 1] << ": " << words_size << endl;

        for (int i = 0; i < MAX_SIZE; i++) {
            cout << ((words[i] == "") ? "" : words[i] + "\n");
        }
    return 0;
}

