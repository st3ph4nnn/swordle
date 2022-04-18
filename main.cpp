#include "main.hpp"
#include "game.hpp"

int main() {
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_MAXIMIZED);
    InitWindow(0, 0, "swordle");
    sounds::init();

    ToggleFullscreen();

    GuiSetStyle(DEFAULT, TEXT_SIZE, 60);

    gameloop();
}