# lab1_2026


pacman -S mingw-w64-ucrt-x86_64-gdb 
pacman -S mingw-w64-ucrt-x86_64-gcc

gcc -std=c17 -Wall -Wextra -Wpedantic -Wconversion -g hello.c -o hello.exe 
.\hello.exe 

gcc -std=c17 -Wall -Wextra -Wpedantic -Wconversion -g hello.c -o hello.exe -mconsole