#pragma once

#include "include/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "include/SFX/button.hpp"
#include "include/SFX/good.hpp"
#include "include/SFX/invalid.hpp"
#include "include/SFX/lost.hpp"
#include "include/SFX/won.hpp"

namespace sounds {
    Sound good, invalid, lost, won, button;
    void init() {
        InitAudioDevice();
        good = LoadSoundFromWave(LoadWaveFromMemory(".wav", goods, sizeof(goods)));
        lost = LoadSoundFromWave(LoadWaveFromMemory(".wav", losts, sizeof(losts)));
        won = LoadSoundFromWave(LoadWaveFromMemory(".wav", wons, sizeof(wons)));
        invalid = LoadSoundFromWave(LoadWaveFromMemory(".wav", invalids, sizeof(invalids)));
        button = LoadSoundFromWave(LoadWaveFromMemory(".wav", clicks, sizeof(clicks)));
    }
}

char get_key(int key) {
    if (key >= 65 && key <= 90)
        return (char)key;

    if (key == 259) return '-';
    if (key == 257) return '+';

    return '\0';
}

void draw_text(char txt, int posx, int posy, int size, Color col) {
    std::string x;
    x += txt;
    DrawText(x.c_str(), posx, posy, size, col);
}

Color get_color(int pos, char x, std::string y, std::string z) {
    Color temp = BLACK;

    switch (std::count(y.begin(), y.end(), x)) {
    case 1:
        temp = DARKBLUE;
        break;
    case 2:
        temp = DARKPURPLE;
        break;
    case 3:
        temp = PURPLE;
        break;
    }

    if (z[pos] == y[pos]) {
        temp = DARKGREEN;
        if (std::count(y.begin(), y.end(), x) > 1)
            temp = YELLOW;
    }

    return temp;
}

bool contains_file(std::string word) {
    std::ifstream fin("wordlist");

    for (int i = 0; i < word.length(); i++)
        word[i] = std::tolower(word[i]);

    std::string search;
    while (std::getline(fin, search))
        if (word == search)
            return true;

    return false;
}

std::string get_word() {
    std::ifstream fin("wordlist");
    std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::uniform_int_distribution<> rng{1, 5757};

    int x = rng(mersenne);

    std::string word;
    while (x-- && std::getline(fin, word))
        continue;

    for (int i = 0; i < word.length(); i++)
        word[i] = std::toupper(word[i]);

    return word;
}