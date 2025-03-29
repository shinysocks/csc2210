#include <raylib.h>

class Window {
    private:
        const int WIDTH = 500;
        const int HEIGHT = 500;
        const char* SPACE_TEXT = "[space]";
        const char* DOT = ".";
        const char* DASH = "-";
        const char* INVALID_CODE = "?";

        bool is_dot;
        int countdown_timer;
        char decoded_char = '\0';
        char* message;

    public:
        Window();
        ~Window();

        /* 
         * wraps raylib rendering.. call BeginDrawing(); ClearBackground();
         * draw everything; call EndDrawing()
         */
        void render();
        void is_symbol_dot(bool);
        void set_countdown(int, char);
        void set_message(const char*);
};
