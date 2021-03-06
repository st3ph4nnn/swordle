# Swordle

![image](https://user-images.githubusercontent.com/67066397/162624780-3cb9e35c-7d7d-4c62-b543-525cd792263d.png)
![image](https://user-images.githubusercontent.com/67066397/162624743-58574694-1bc2-4c51-b170-0b5d041e9674.png)

Swordle is a Wordle-like game made by stephan, using C++17 and RAYLIB 4.0  
Raylib: https://www.raylib.com/  
Wordle explained: https://en.wikipedia.org/wiki/Wordle

**Feature list:**
- Changeable wordlist (see FAQ)
- 5761 5 letter words default to be used from the english dictionary
- Some Sound Effects
- A little bit easier than the real wordle

# FAQ

1. How can i play the game?

Go to the releases page on the right side of the page, and download the latest .ZIP file  
After that, extract it in a directory and open swordle.exe (if you are on windows);

If you are on linux, open a terminal in the directory, type **chmod +x game**,  
then play the game using ./game in the same directory.

2. Can i change the wordlist?

Yes you can, but as for now, the wordlist **MUST** have 5761 lines, or else the game might break.  
Edit the wordlist at your own risk.

3. Why its not picking any words?

The game will warn you if there is no list available.  
If you however have the list, edit it, copy everything inside, delete, save it,  
open it again, paste, save again, and issues should be gone. Remember, the list  
must have 5761 LINES and be in the same DIRECTORY as the game!

# Known issues

Your screen must have atleast the resolution HD, lower than that, it wont work.

# For developers

## Windows

In order to properly build the game, you will need:

- An IDE of choice
- Latest MinGW x64 DevKit: https://github.com/skeeto/w64devkit (add it to path)
- A terminal

After that, go in to the **build** directory and type in the terminal **mingw32-make.exe**  
Wait a few seconds, and your game should be compiled in the directory 'windows/'

! Remember to copy wordlist to the folder you have built for! (its very important!)

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
- make PLATFORM=PLATFORM_DESKTOP (if you want to support older hardware, type: "GRAPHICS=GRAPHICS_API_OPENGL_31" here)
- sudo make install

Great. Now you are able to go download the game source, and go in to the build/ folder,  
and type **make OS=LINUX**

! Remember to copy wordlist to the folder you have built for! (its very important!)

