#include <raylib.h>
#include <iostream>
#include "morsetree.h"
#include "window.h"
#include <fstream>
#include <vector>

using namespace std;

const string DASH = "-";
const string DOT  = ".";
vector<string> valid_codes = vector<string>();

MorseTree load_codes() {
    MorseTree tree = MorseTree();
    ifstream file("codes.txt");

    string line;
    while (getline(file, line)) {
        const string code = line.substr(1, line.length());
        valid_codes.push_back(code);
        tree.add(line[0], code);
    }

    file.close();
    cout << "loaded morsetree from 'codes.txt'" << endl;
    return tree;
}

// less than 0.6 second is a dot
bool is_dot(double elapsed) {
    if (elapsed < 0.60)
        return true;
    return false;
}

bool is_valid(string code) {
    for (string c : valid_codes) {
        if (c == code)
            return true;
    } return false;
}

int main() {
    // load morsetree from codes.txt
    MorseTree tree = load_codes();
    Window win = Window();

    double down_elapsed = 0.0;
    double up_elapsed = 0.0;
    string message = "";
    string code = "";
    char decoded_c = '\0';
    bool symbol_is_dot = false;
    bool decoded_c_is_appended = false;

    while (!WindowShouldClose()) {
        // get elapsed time that space has been held down
        if (IsKeyPressed(KEY_SPACE)) {
            down_elapsed = GetTime();
        } if (IsKeyReleased(KEY_SPACE)) {
            symbol_is_dot = is_dot(GetTime() - down_elapsed);
            win.is_symbol_dot(symbol_is_dot);
            code.append((symbol_is_dot) ? DOT : DASH); 
            decoded_c_is_appended = false;
            up_elapsed = GetTime();

        } if (!IsKeyDown(KEY_SPACE)) {
            int countdown = 3 - ((int) (GetTime() - up_elapsed));
            win.set_countdown(countdown, decoded_c);

            // singleton
            if (!decoded_c_is_appended && countdown == 0) {
                if (is_valid(code)) {
                    decoded_c = tree.decode(code);
                    message += decoded_c;
                } else {
                    decoded_c = '\0';
                }
                code = "";
                decoded_c_is_appended = true;
            }

            // wait additional second
            if (countdown < 0) {
                decoded_c = '\0';
                up_elapsed = GetTime();
            }
        }
        win.set_message(message.c_str());
        win.render();
    }

    CloseWindow();
    return 0;
}

