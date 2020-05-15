#include "Board.h"
#include "ReversiAlgorithm.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#define WHITE 1
#define BLACK 2

void startGame();
void startGame2();
void test();

int main(){
    Board b;
    BitBoard wb = 0x0200000000000000;
    BitBoard bb = 0x01472F3F7FBE7FFE;
    b.set_Board(wb, bb);

    b.printb();
    printf("BLACK = %d\n", count(*b.get_Board(BLACK)));
    printf("WHITE = %d\n", count(*b.get_Board(WHITE)));

    BitBoard moves;
    moves = b.getValidMoves(BLACK);
    
    printf("\n");
    printf("flipped disks = %d\n",b.move(49,BLACK));
    b.printb(moves);

    int n;
    scanf("%d", &n);
    // startGame();
    // test();
    return 0;
}

void startGame(){
    printf("WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    int x, y;
    Board b;
    b.printb();
    ReversiAlgorithm ai;
    int color = BLACK;

    for(int i = 0; i<64; i++){
        (color == 1 )? printf("WHITE(@)\n"):printf("BLACK(O)\n");
        if ( color == 2 ){
            printf("x pos:");
            scanf("%d", &x);
            printf("y pos:");
            scanf("%d", &y);
            printf("\n");
            // b.move(x, y, color)?printf("successfully moved\n"):printf("could not move\n");
            while(!b.move(getPos(x, y), color)){
                printf("Please select a legal move!\n");
                printf("x pos:");
                scanf("%d", &x);
                printf("y pos:");
                scanf("%d", &y);
                printf("\n");
            }
        }else{
            BitBoard wb, bb;
            b.get_Board(&wb, &bb);
            int move = ai.getNextMove(wb, bb, color);
            printf("AI moved:%d\n", move);
            b.move(move,color);
        }

        printf("White Disks(@):");
        printf("%d\n", count(*b.get_Board(WHITE)));
        printf("Black Disks(O):");
        printf("%d\n", count(*b.get_Board(BLACK)));
        b.printb();
        color = 3 - color;
    }
    std::wcin >> x;
}

void startGame2(){
    printf("WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    int x, y;
    Board b;
    int color = BLACK;
    BitBoard moves = b.getValidMoves(color);
    b.printb(moves);
    ReversiAlgorithm ai;

    for(int i = 0; i<64; i++){
        printf("\n");        
        (color == 1 )? printf("WHITE(@)\n"):printf("BLACK(O)\n");
        printf("x pos:");
        scanf("%d", &x);
        printf("y pos:");
        scanf("%d", &y);
        printf("\n");
        // b.move(x, y, color)?printf("successfully moved\n"):printf("could not move\n");
        while(!b.move(getPos(x, y), color)){
            printf("Please select a legal move!\n");
            printf("x pos:");
            scanf("%d", &x);
            printf("y pos:");
            scanf("%d", &y);
            printf("\n");
        }

        color = 3 - color;
        moves = b.getValidMoves(color);
        printf("White Disks(@):");
        printf("%d\n", count(*b.get_Board(WHITE)));
        printf("Black Disks(O):");
        printf("%d\n", count(*b.get_Board(BLACK)));
        b.printb(moves);
        
    }
    std::wcin >> x;
}

void test(){
    printf("WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    Board b;
    ReversiAlgorithm ai;

    BitBoard wb = 0x000004081E040000;
    BitBoard bb = 0x0000203020380800;
    b.set_Board(wb, bb);

    BitBoard m;
    m = b.getValidMoves(BLACK);
    int i;
    for(i=0;i<64;i++){
        if(getBit(m, i) == 1ull) printf("%d, ", i);
    }
    printf("\n");

    b.printb(m);
    int color = BLACK;

    int num;
    std::vector<int> moves = ai.getAvailableMoves(color, &num);

    for(auto itr = moves.begin(); itr != moves.end(); ++itr){
        printf("%d, ",*itr);
    }
    printf("\n");
    std::wcin >> num;

}