#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

int display_menu();
void display_tetris();
int game;
int update(int signum);
int x = 3;
int y = 0;
int point = 0;


#define GAME_START 0
#define GAME_END 1
int game_start();

int main(void)
{
    int menu = 1;
    menu = display_menu();

    switch (menu){
        case 1: //gamestart
            printf("1. Game Start\n");
            game = GAME_START;
            menu = game_start();
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

int game_start()
{
    //signal설정
    static struct itimerval timer;
    signal(SIGVTALRM, update);
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 16667;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 16667;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    if(game == GAME_START){
        while(1){
            x = 3;
            y = 0;
            point = 0;

            return 1;
        }
    }
    game = GAME_END;
}