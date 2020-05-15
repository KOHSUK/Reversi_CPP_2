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
    wprintf(L"WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    int x, y;
    Board b;
    b.printb();
    ReversiAlgorithm ai;
    int color = BLACK;

    for(int i = 0; i<64; i++){
        (color == 1 )? wprintf(L"WHITE(@)\n"):wprintf(L"BLACK(O)\n");
        if ( color == 2 ){
            wprintf(L"x pos:");
            wscanf(L"%d", &x);
            wprintf(L"y pos:");
            wscanf(L"%d", &y);
            wprintf(L"\n");
            // b.move(x, y, color)?wprintf(L"successfully moved\n"):wprintf(L"could not move\n");
            while(!b.move(getPos(x, y), color)){
                wprintf(L"Please select a legal move!\n");
                wprintf(L"x pos:");
                wscanf(L"%d", &x);
                wprintf(L"y pos:");
                wscanf(L"%d", &y);
                wprintf(L"\n");
            }
        }else{
            BitBoard wb, bb;
            b.get_Board(&wb, &bb);
            int move = ai.getNextMove(wb, bb, color);
            wprintf(L"AI moved:%d\n", move);
            b.move(move,color);
        }

        wprintf(L"White Disks(@):");
        wprintf(L"%d\n", count(*b.get_Board(WHITE)));
        wprintf(L"Black Disks(O):");
        wprintf(L"%d\n", count(*b.get_Board(BLACK)));
        b.printb();
        color = 3 - color;
    }
    std::wcin >> x;
}

void startGame2(){
    wprintf(L"WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    int x, y;
    Board b;
    int color = BLACK;
    BitBoard moves = b.getValidMoves(color);
    b.printb(moves);
    ReversiAlgorithm ai;

    for(int i = 0; i<64; i++){
        wprintf(L"\n");        
        (color == 1 )? wprintf(L"WHITE(@)\n"):wprintf(L"BLACK(O)\n");
        wprintf(L"x pos:");
        wscanf(L"%d", &x);
        wprintf(L"y pos:");
        wscanf(L"%d", &y);
        wprintf(L"\n");
        // b.move(x, y, color)?wprintf(L"successfully moved\n"):wprintf(L"could not move\n");
        while(!b.move(getPos(x, y), color)){
            wprintf(L"Please select a legal move!\n");
            wprintf(L"x pos:");
            wscanf(L"%d", &x);
            wprintf(L"y pos:");
            wscanf(L"%d", &y);
            wprintf(L"\n");
        }

        color = 3 - color;
        moves = b.getValidMoves(color);
        wprintf(L"White Disks(@):");
        wprintf(L"%d\n", count(*b.get_Board(WHITE)));
        wprintf(L"Black Disks(O):");
        wprintf(L"%d\n", count(*b.get_Board(BLACK)));
        b.printb(moves);
        
    }
    std::wcin >> x;
}

void test(){
    wprintf(L"WHITE(@) = 1, BLACK(O) = 2: input (1/2)\n");
    Board b;
    ReversiAlgorithm ai;

    BitBoard wb = 0x000004081E040000;
    BitBoard bb = 0x0000203020380800;
    b.set_Board(wb, bb);

    BitBoard m;
    m = b.getValidMoves(BLACK);
    int i;
    for(i=0;i<64;i++){
        if(getBit(m, i) == 1ull) wprintf(L"%d, ", i);
    }
    wprintf(L"\n");

    b.printb(m);
    int color = BLACK;

    int num;
    std::vector<int> moves = ai.getAvailableMoves(color, &num);

    for(auto itr = moves.begin(); itr != moves.end(); ++itr){
        wprintf(L"%d, ",*itr);
    }
    wprintf(L"\n");
    std::wcin >> num;

}