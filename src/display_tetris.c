#include "display_tetris.h"

extern int block_state = 0;

void display_tetris()
{
    system("clear");
    printf("Next Block\n");
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if (block[block_state][i][j] == 0){
                printf("o ");
            }else{
                printf("* ");
            }
            
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Tetris_Table\n");
    for (int i = 2; i < 21; ++i){
        printf("\t");
        for(int j = 0; j < 10; ++j){
            if((j == 0 || j == 9) && (i < 20)){
                printf("|");
            }else if(i == 20 && (j > 1 || j < 9)){
                printf("=");
            }else if(tetris_table[j][i] == 0){
                printf("o");
            }else if (tetris_table[j][i] == 1){
                printf("*");
            }
            
        }
        printf("\n");
    }
}