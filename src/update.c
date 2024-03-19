#include <stdio.h>

extern int x;       //extern을 사용하여 main에서 선언한 변수를 여기서도 쓰겠다
extern int y;
int block_state = 0;
extern int block[4][4][4];

//#define DONW 0
//#define LEFT 1
//#define RIGHT 2
//#define ROTATE 3

typedef enum{
    DOWN,
    LEFT,
    RIGHT,
    ROTATE
} COMMAND;


int test = 0;
int update(int signum)
{
    display_tetris();
    test++;
    printf("%d\n", test);
}

int move_block(int command)
{
    int i, j;
    int newx, newy;
    int oldx, oldy;
    int old_block_state;

    newx = x;
    newy = y;
    old_block_state = block_state;

    if(collision_test(command) == 0){
        switch(command){
            case DOWN:
                newy++;
                break;
            case LEFT:
                newx--;
                break;
            case RIGHT:
                newx++;
                break;
            case ROTATE:
                block_state++;
                if(block_state > 3){
                    block_state = 0;
                }
                break;
            
        }
    }
}

// tetris table의 old block 제거
for(i = 0, oldy = y; i < 4; ++i, ++oldy){
    for (j = 0, oldx = x; j < 4; ++j, ++oldx){
        if(block[old_block_state][i][j] == 1){
            tetris_table[oldy][oldx] = 0;
        }
    }
}

// tetris table 에 블럭 추가
x = newx;
y = newy;
for(i = 0, newy = y; i < 4; ++i){
    for(j = 0, newx = x; j < 4; ++j){
        if(newx > 0 && newx < 9 && newy < 20 && newy > 0){
            tetris_table[newy][newx] = block[block_state][i][j];
        }
    }
    return 0;
}

int collision_test(int command)
{
    int i, j;
    int tempx, tempy;
    int oldx, oldy;
    int temp_block_state;
    int temp_tetris_table[21][10];

    //daisy chain
    oldx = tempx = x;
    oldy = tempy = y;
    temp_block_state = block_state;

    
    switch(command){
        case DOWN:
            tempy++;
            break;
        case LEFT:
            tempx--;
            break;
        case RIGHT:
            tempx++;
            break;
        case ROTATE:
            temp_block_state++;
            if(temp_block_state > 3){
                temp_block_state = 0;
            }
            break;
        
    }

    //tetris_table을 temp_tetris_table로 복사
    for(i = 0; i < 21; ++i){
        temp_tetris_table[i][j] = tetris_table[i][j];
    }

    //collision check
    for(i = 0; i < 4; ++i){
        for(j = 0; j < 4; ++j){
            if(temp_tetris_table[temp+i][temp+j] == 1 && block[temp_block_state][i][j] == 1){
                return 1;
            }
        }
    }
    return 0;

}