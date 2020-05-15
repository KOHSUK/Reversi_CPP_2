#pragma once
#include <stdint.h>
#include <stdio.h>
#define AVAILABLE_MAX 64

typedef uint64_t BitBoard;

int getPos(wchar_t *pos);

int getPos(int x, int y);

int count(BitBoard b);

BitBoard getBits(BitBoard b, int pos, int n);

BitBoard getBit(BitBoard b, int pos);

void printBitBoard(BitBoard b);

class Board {
private:
    //White
    BitBoard wBoard;
    BitBoard wSavePoint;

    //Black
    BitBoard bBoard;
    BitBoard bSavePoint;

    //Holes
    BitBoard holes;

    BitBoard translate(BitBoard pos, int index);

public:

    Board();

    Board(BitBoard w, BitBoard b);

    Board(BitBoard w, BitBoard b, BitBoard h);

    BitBoard getValidMoves(int color);

    int move(int pos, int color);

    void printb(BitBoard anothoer);

    void printb();

    BitBoard* get_Board(int color);

    void get_Board(BitBoard *wb, BitBoard *bb);

    void set_Board(BitBoard wb, BitBoard bb);

    void saveBoard();

    void roolback();

};