#pragma once
#include "main.hpp"

void gameloop();

std::vector<std::string> words = {"", "", "", "", "", ""};
std::vector<std::string> words_used;
std::vector<char> chars_available = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::string word = get_word();
int current = 0;
bool played;
bool finished;
bool audio = true;

bool info() {
    int width = GetMonitorWidth(0);
    int height = GetMonitorHeight(0);

    while (!WindowShouldClose()) {
        Rectangle back{width / 2 - 150, height - (IsWindowFullscreen() ? 190 : 200), 300, 75};
        Rectangle full{width / 2 - 500, height - (IsWindowFullscreen() ? 190 : 200), 300, 75};
        Rectangle aud{width / 2 + 200, height - (IsWindowFullscreen() ? 190 : 200), 300, 75};

        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("Game Info", width / 2 - MeasureText("Game Info", 90) / 2, 20, 90, BLACK);
        DrawText("Wordle-Like Game in C++ using RAYLIB", width / 2 - MeasureText("Wordle-Like Game in C++ using RAYLIB", 35) / 2, 130, 35, BLACK);

        DrawText("G", width / 2 - 620, 188, 60, DARKGREEN);
        DrawText("- The letter is placed in the right spot and it contains the word once", width / 2 - 550, 200, 30, BLACK);

        DrawText("G", width / 2 - 620, 252, 60, DARKBLUE);
        DrawText("- The letter is NOT placed in the right spot and it contains the word once", width / 2 - 550, 270, 30, BLACK);

        DrawText("G", width / 2 - 620, 316, 60, DARKPURPLE);
        DrawText("- The letter is NOT placed in the right spot and it contains the word TWICE", width / 2 - 550, 334, 30, BLACK);

        DrawText("G", width / 2 - 620, 380, 60, PURPLE);
        DrawText("- The letter is NOT placed in the right spot and it contains the word THRICE", width / 2 - 550, 398, 30, BLACK);

        DrawText("G", width / 2 - 620, 444, 60, YELLOW);
        DrawText("- The letter is placed in the right spot and it contains the word > 1 TIMES", width / 2 - 550, 462, 30, BLACK);

        if (GuiButton(back, "back")) {
            if (audio)
                PlaySound(sounds::button);

            EndDrawing();
            gameloop();
        }

        if (GuiButton(full, "fullscreen")) {
            if (audio)
                PlaySound(sounds::button);

            ToggleFullscreen();
        }

        if (GuiButton(aud, "audio")) {
            audio = !audio;
            if (audio)
                PlaySound(sounds::button);
        }

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    exit(0);
}

void gameloop() {
    int width = GetMonitorWidth(0);
    int height = GetMonitorHeight(0);

    Rectangle infob{width - 310,
                    10, 300, 75};

    Rectangle quitb{width - 310,
                    95, 300, 75};

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        if (word == "wordlist") {
            DrawText("ERROR: the word list wasnt found!", width / 2 - MeasureText("ERROR: the word list wasnt found!", 60) / 2, height / 2 - 30, 60, RED);
            EndDrawing();
            continue;
        }

        DrawText("press DELETE to reset", width / 2 - MeasureText("press DELETE to reset", 40) / 2, 20, 40, BLACK);

        if (IsKeyPressed(KEY_DELETE)) {
            if (audio)
                PlaySound(sounds::button);

            finished = false;
            played = false;
            words = {"", "", "", "", "", ""};
            words_used = {};
            chars_available = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            current = 0;
            word = get_word();
        }

        DrawText("SWORDLE - made by stephan", width / 2 - MeasureText("SWORDLE - made by stephan", 40) / 2, height - (IsWindowFullscreen() ? 60 : 70), 40, BLACK);

        if (GuiButton(infob, "info")) {
            if (audio)
                PlaySound(sounds::button);

            EndDrawing();
            info();
        }

        if (GuiButton(quitb, "quit")) {
            if (audio)
                PlaySound(sounds::button);

            EndDrawing();
            CloseWindow();
            CloseAudioDevice();
            exit(0);
        }

        DrawRectangleLines(width / 2 - 351, height / 2 - 301, 702, 602, BLACK);
        DrawRectangle(width / 2 - 350, height / 2 - 300, 700, 600, LIGHTGRAY);

        for (int i = 1; i < 6; i++)
            DrawLine(width / 2 - 350, height / 2 - 300 + 100 * i, width / 2 - 350 + 700, height / 2 - 300 + 100 * i, BLACK);

        for (int i = 1; i < 5; i++)
            DrawLine(width / 2 - 350 + 140 * i, height / 2 - 300, width / 2 - 350 + 140 * i, height / 2 - 300 + 600, BLACK);

        if (!finished) {
            int pressed = GetKeyPressed();

            if (pressed) {
                char key = get_key(pressed);

                switch (key) {
                case '\0':
                    continue;
                    break;
                case '+':
                    if (words[current].length() == 5) {
                        if (contains_file(words[current])) {
                            words_used.emplace_back(words[current]);
                            for (char x : words[current])
                                for (int i = 0; i < chars_available.size(); i++)
                                    if (chars_available[i] == x)
                                        chars_available.erase(chars_available.begin() + i);
                            current++;
                            current = std::clamp(current, 0, 5);
                            if (audio)
                                PlaySound(sounds::good);
                        } else {
                            if (audio)
                                PlaySound(sounds::invalid);
                            DrawText(("invalid: " + words[current]).c_str(), width / 2 - MeasureText(("invalid: " + words[current]).c_str(), 60) / 2, 15, 60, RED);
                            std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        }
                    }
                    break;
                case '-':
                    if (words[current].length() > 0)
                        words[current].erase(words[current].length() - 1);
                    break;
                default:
                    if (words[current].length() < 5)
                        words[current] += key;
                    break;
                }
            }

            DrawText("available", 20, 10, 30, BLUE);
            for (int j = 0; j < chars_available.size() / 2; j++)
                draw_text(chars_available[j], 20, 40 + j * 55, 50, BLACK);

            for (int j = chars_available.size() / 2; j < chars_available.size(); j++)
                draw_text(chars_available[j], 70, 40 + (j - chars_available.size() / 2) * 55, 50, BLACK);

            for (int i = 0; i < words.size(); i++) {
                if (words[i] == "") break;

                for (int j = 0; j < words[i].length(); j++)
                    draw_text(words[i][j], width / 2 - 350 + 40 + 140 * j, height / 2 - 300 + 5 + 100 * i, 100, (std::count(words_used.begin(), words_used.end(), words[i]) ? get_color(j, words[i][j], word, words[i]) : BLACK));

                if (!played) {
                    if (std::count(words_used.begin(), words_used.end(), word)) {
                        GuiDisable();
                        if (audio)
                            PlaySound(sounds::won);
                        finished = true;
                        played = true;
                        continue;
                    }

                    if (words_used.size() == 6) {
                        GuiDisable();
                        if (audio)
                            PlaySound(sounds::lost);
                        finished = true;
                        played = true;
                        continue;
                    }
                }
            }
        } else {
            for (int i = 0; i < 6; i++) {
                if (words[i] == "") break;

                for (int j = 0; j < words[i].length(); j++)
                    draw_text(words[i][j], width / 2 - 350 + 40 + 140 * j, height / 2 - 300 + 5 + 100 * i, 100, (std::count(words_used.begin(), words_used.end(), words[i]) ? get_color(j, words[i][j], word, words[i]) : BLACK));
            }

            DrawRectangle(0, 0, width, height, ColorAlpha(LIGHTGRAY, 0.6));
            DrawText(("The word was: " + word).c_str(), width / 2 - MeasureText(("The word was: " + word).c_str(), 80) / 2, height / 2 - 200, 80, BLACK);
            DrawText("Press ENTER to play again", width / 2 - MeasureText("Press ENTER to play again", 60) / 2, height / 2 - 30, 60, BLACK);

            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(335)) {
                if (audio)
                    PlaySound(sounds::button);

                GuiEnable();
                finished = false;
                played = false;
                words = {"", "", "", "", "", ""};
                words_used = {};
                chars_available = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
                current = 0;
                word = get_word();
            }
        }

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    exit(0);
}