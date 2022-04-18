# Swordle

![image](https://user-images.githubusercontent.com/67066397/162624780-3cb9e35c-7d7d-4c62-b543-525cd792263d.png)
![image](https://user-images.githubusercontent.com/67066397/162624743-58574694-1bc2-4c51-b170-0b5d041e9674.png)

Swordle is a Wordle-like game made by stephan, using C++17 and RAYLIB 4.0  
Raylib: https://www.raylib.com/  
Wordle explained: https://en.wikipedia.org/wiki/Wordle

**Feature list:**
- Changeable wordlist (see FAQ)
- 5353 5 letter words default to be used from the english dictionary
- Some Sound Effects
- A little bit easier than the real wordle

# FAQ

1. How can i play the game?

Go to the releases page on the right side of the page, and download the latest .ZIP file  
After that, extract it in a directory and open swordle.exe

2. Can i change the wordlist?

Yes you can, but as for now, the wordlist **MUST** have 5353 lines, or else the game might break.  
Edit the wordlist at your own risk.

# Known issues

Your screen must have atleast the resolution HD, lower than that, it wont work.

# For developers

## Windows

In order to properly build the game, you will need:

- An IDE of choice
- Latest MinGW x64 DevKit: https://github.com/skeeto/w64devkit (add it to path)
- A terminal

After that, go in to the **build** directory and type in the terminal **mingw32-make.exe OS=WINDOWS**  
Wait a few seconds, and your game should be compiled in the directory 'windows/'

## Linux

In order to properly build the game, you will need:

- An IDE of choice
- A terminal
- Latest g++ version (tested on 7.5.0)

After that, install these:

### Ubuntu-based

***sudo apt install git libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev***

### Redhat-based

***sudo dnf install git alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel***

After that, you will need to do the following commands in a temporary directory:

- git clone https://github.com/raysan5/raylib.git raylib
- cd raylib/src/
- make PLATFORM=PLATFORM_DESKTOP
- sudo make install

Great. Now you are able to go download the game source, and go in to the build/ folder,  
and type **make OS=LINUX**

