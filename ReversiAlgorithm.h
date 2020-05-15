#pragma once
#include "Board.h"
#include <vector>

class ReversiAlgorithm{
private:
    Board board;

    int getIntRand(int st, int en);

    int MoveAtRandom(std::vector<int> moves, int num, int color, int i);

    int playout(int color);

public:
    ReversiAlgorithm();

    int getNextMove(BitBoard wb, BitBoard bb, int color);
    
    std::vector<int> getAvailableMoves(int color, int *num);

};