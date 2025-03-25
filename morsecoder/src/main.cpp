#include <raylib.h>

void write_text(const char* text) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(text, 20, 20, 40, GREEN);
    EndDrawing();
}

int main() {
    InitWindow(400, 400, "morsecoder");
    SetWindowOpacity(0.5);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_SPACE))
            write_text("space down!");
        else
            write_text("how are you?");
    }

    CloseWindow();
    return 0;
}
