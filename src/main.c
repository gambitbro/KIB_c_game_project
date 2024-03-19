#include <stdio.h>

int display_menu();
void display_tetris();

int main(void)
{
    int menu = 1;
    menu = display_menu();

    switch (menu){
        case 1: //gamestart
            printf("1. Game Start\n");
            display_tetris();
            break;
        case 2: //search history
            printf("2. Search History\n");
            break;
        case 3: //record output
            printf("3. Record Output\n");
            break;
        case 4: //quit
            printf("4. Quit\n");
            break;

    }
    printf("Hello, World!\n");
    return 0;
}