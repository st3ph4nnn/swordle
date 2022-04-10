# Swordle

![image](https://user-images.githubusercontent.com/67066397/162624709-de100ab4-6c0f-4ce1-a227-f62d874bfc5d.png)
![image](https://user-images.githubusercontent.com/67066397/162624743-58574694-1bc2-4c51-b170-0b5d041e9674.png)


Swordle is a Wordle-like game made by stephan, using C++17 and RAYLIB 4.0  
Raylib: https://www.raylib.com/  
Wordle explained: https://en.wikipedia.org/wiki/Wordle

**Feature list:**
- Changeable wordlist (see FAQ)
- 5353 5 letter words default to be used from the english dictionary
- Some Sound Effects
- ... More to come

# FAQ

1. How can i play the game?

Go to the releases page on the right side of the page, and download the latest .ZIP file  
After that, extract it in a directory and open swordle.exe

2. Can i change the wordlist?

Yes you can, but as for now, the wordlist **MUST** have 5353 lines, or else the game might break.  
Edit the wordlist at your own risk.

# KNOWN ISSUES

The game can only be ran with aspect ratio 16:9, since there is  
an issue with scaling too and im lazy to fix it

# FOR DEVELOPERS

In order to properly build the game, you will need:

- An IDE of choice
- Latest MinGW x64 DevKit: https://github.com/skeeto/w64devkit (add it to path)
- A terminal

After that, go in to the **build** directory and type in the terminal **mingw32-make.exe**  
Wait a few seconds, and your game should be compiled in the same directory.
