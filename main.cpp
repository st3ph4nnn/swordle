#include "main.hpp"
#include "game.hpp"

int main() {
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(0, 0, "swordle");
    sounds::init();
    cam.zoom = GetScreenWidth() / 1366.f;
    SetCam(cam);
    ToggleFullscreen();

    GuiSetStyle(DEFAULT, TEXT_SIZE, 60);

    gameloop();
}