#include "window.h"
#include "iostream"
#include "raylib.h"

Window::Window() {
    InitWindow(WIDTH, HEIGHT, "morsecoder");
    const std::string s = "";
    message = (char*) s.c_str();
}

void Window::render() {
    BeginDrawing();
    ClearBackground(BLACK);

    // draw everything
    if (IsKeyDown(KEY_SPACE)) {
        DrawText(SPACE_TEXT, 178, 270, 40, PURPLE); // fix pos
    }

    if (is_dot) {
        DrawText(DOT, 235, 35, 200, GREEN); // fix pos
    } else {
        DrawText(DASH, 210, 100, 200, GREEN); // fix pos
    }

    // draw countdown
    if (countdown_timer == 0) {
        if (decoded_char == '\0') {
            DrawText(INVALID_CODE, 17, 15, 50, RED);
        } else {
            DrawText(&decoded_char, 25, 10, 50, GREEN);
        }
    } else {
        DrawText(std::to_string(countdown_timer).c_str(), 20, 15, 50, BLUE);
    }

    DrawText(message, 100, 370, 40, WHITE);
    EndDrawing();
}

void Window::is_symbol_dot(const bool _is_dot) {
    is_dot = _is_dot;
}

void Window::set_countdown(int count, const char c) {
    countdown_timer = count;
    decoded_char = c;
}

void Window::set_message(const char* m) {
    message = (char*) m;
}
