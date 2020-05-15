#include "ReversiAlgorithm.h"
#include "Board.h"
#include <algorithm>
#include <random>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#define PLAYOUT_COUNT 100

void printMoves(BitBoard moves);

std::vector<int> ReversiAlgorithm::getAvailableMoves(int color, int *num){
    BitBoard m = board.getValidMoves(color);
    std::vector<int> moves;
    *num = count(m);
    // board.printb();
    // printMoves(m);
    // int i;
    // for(i=0;i<64;i++){
    //     if(getBit(m, i) == 1ull) moves.push_back(i);
    // }

    if( (0b0000000000000000000000000000000000000000000000000000000000000001ull & m) > 0ull ) moves.push_back(0);
    if( (0b0000000000000000000000000000000000000000000000000000000000000010ull & m) > 0ull ) moves.push_back(1);
    if( (0b0000000000000000000000000000000000000000000000000000000000000100ull & m) > 0ull ) moves.push_back(2);
    if( (0b0000000000000000000000000000000000000000000000000000000000001000ull & m) > 0ull ) moves.push_back(3);
    if( (0b0000000000000000000000000000000000000000000000000000000000010000ull & m) > 0ull ) moves.push_back(4);
    if( (0b0000000000000000000000000000000000000000000000000000000000100000ull & m) > 0ull ) moves.push_back(5);
    if( (0b0000000000000000000000000000000000000000000000000000000001000000ull & m) > 0ull ) moves.push_back(6);
    if( (0b0000000000000000000000000000000000000000000000000000000010000000ull & m) > 0ull ) moves.push_back(7);
    if( (0b0000000000000000000000000000000000000000000000000000000100000000ull & m) > 0ull ) moves.push_back(8);
    if( (0b0000000000000000000000000000000000000000000000000000001000000000ull & m) > 0ull ) moves.push_back(9);
    if( (0b0000000000000000000000000000000000000000000000000000010000000000ull & m) > 0ull ) moves.push_back(10);
    if( (0b0000000000000000000000000000000000000000000000000000100000000000ull & m) > 0ull ) moves.push_back(11);
    if( (0b0000000000000000000000000000000000000000000000000001000000000000ull & m) > 0ull ) moves.push_back(12);
    if( (0b0000000000000000000000000000000000000000000000000010000000000000ull & m) > 0ull ) moves.push_back(13);
    if( (0b0000000000000000000000000000000000000000000000000100000000000000ull & m) > 0ull ) moves.push_back(14);
    if( (0b0000000000000000000000000000000000000000000000001000000000000000ull & m) > 0ull ) moves.push_back(15);
    if( (0b0000000000000000000000000000000000000000000000010000000000000000ull & m) > 0ull ) moves.push_back(16);
    if( (0b0000000000000000000000000000000000000000000000100000000000000000ull & m) > 0ull ) moves.push_back(17);
    if( (0b0000000000000000000000000000000000000000000001000000000000000000ull & m) > 0ull ) moves.push_back(18);
    if( (0b0000000000000000000000000000000000000000000010000000000000000000ull & m) > 0ull ) moves.push_back(19);
    if( (0b0000000000000000000000000000000000000000000100000000000000000000ull & m) > 0ull ) moves.push_back(20);
    if( (0b0000000000000000000000000000000000000000001000000000000000000000ull & m) > 0ull ) moves.push_back(21);
    if( (0b0000000000000000000000000000000000000000010000000000000000000000ull & m) > 0ull ) moves.push_back(22);
    if( (0b0000000000000000000000000000000000000000100000000000000000000000ull & m) > 0ull ) moves.push_back(23);
    if( (0b0000000000000000000000000000000000000001000000000000000000000000ull & m) > 0ull ) moves.push_back(24);
    if( (0b0000000000000000000000000000000000000010000000000000000000000000ull & m) > 0ull ) moves.push_back(25);
    if( (0b0000000000000000000000000000000000000100000000000000000000000000ull & m) > 0ull ) moves.push_back(26);
    if( (0b0000000000000000000000000000000000001000000000000000000000000000ull & m) > 0ull ) moves.push_back(27);
    if( (0b0000000000000000000000000000000000010000000000000000000000000000ull & m) > 0ull ) moves.push_back(28);
    if( (0b0000000000000000000000000000000000100000000000000000000000000000ull & m) > 0ull ) moves.push_back(29);
    if( (0b0000000000000000000000000000000001000000000000000000000000000000ull & m) > 0ull ) moves.push_back(30);
    if( (0b0000000000000000000000000000000010000000000000000000000000000000ull & m) > 0ull ) moves.push_back(31);
    if( (0b0000000000000000000000000000000100000000000000000000000000000000ull & m) > 0ull ) moves.push_back(32);
    if( (0b0000000000000000000000000000001000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(33);
    if( (0b0000000000000000000000000000010000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(34);
    if( (0b0000000000000000000000000000100000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(35);
    if( (0b0000000000000000000000000001000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(36);
    if( (0b0000000000000000000000000010000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(37);
    if( (0b0000000000000000000000000100000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(38);
    if( (0b0000000000000000000000001000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(39);
    if( (0b0000000000000000000000010000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(40);
    if( (0b0000000000000000000000100000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(41);
    if( (0b0000000000000000000001000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(42);
    if( (0b0000000000000000000010000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(43);
    if( (0b0000000000000000000100000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(44);
    if( (0b0000000000000000001000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(45);
    if( (0b0000000000000000010000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(46);
    if( (0b0000000000000000100000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(47);
    if( (0b0000000000000001000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(48);
    if( (0b0000000000000010000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(49);
    if( (0b0000000000000100000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(50);
    if( (0b0000000000001000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(51);
    if( (0b0000000000010000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(52);
    if( (0b0000000000100000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(53);
    if( (0b0000000001000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(54);
    if( (0b0000000010000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(55);
    if( (0b0000000100000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(56);
    if( (0b0000001000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(57);
    if( (0b0000010000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(58);
    if( (0b0000100000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(59);
    if( (0b0001000000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(60);
    if( (0b0010000000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(61);
    if( (0b0100000000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(62);
    if( (0b1000000000000000000000000000000000000000000000000000000000000000ull & m) > 0ull ) moves.push_back(63);
    return moves;
}

int ReversiAlgorithm::getNextMove(BitBoard wb, BitBoard bb, int color){
    int num = 0;
    board.set_Board(wb, bb);
    int i, win_count, selMove = 0;
    double winRate, maxWinRate = -100.0;
    std::vector<int> moves = getAvailableMoves(color, &num);

    for(auto itr = moves.begin(); itr != moves.end(); ++itr){
        
        board.save();
        board.move(*itr, color);
        win_count = 0;

        //save current board.
        BitBoard tmpW, tmpB;
        board.get_Board(&tmpW, &tmpB);

        //playout 1000 times.
        for(i=0;i<PLAYOUT_COUNT;i++){
            win_count += playout(3 - color);
            board.set_Board(tmpW, tmpB);
        }

        winRate = (double)win_count / PLAYOUT_COUNT;

        //select best move
        if(winRate > maxWinRate) {
            maxWinRate = winRate;
            selMove = *itr;
        }
        
        board.rollback();
    }
    
    printf("Move:%d, WinRate:%f\n", selMove, maxWinRate);
    return selMove;
}

int ReversiAlgorithm::getIntRand(int st, int en){
    std::random_device randomDevice;

    std::vector<uint32_t> randomSeedVector(10);

    std::generate(randomSeedVector.begin(),randomSeedVector.end(),std::ref(randomDevice));

    std::seed_seq randomSeed(randomSeedVector.begin(),randomSeedVector.end());

    std::mt19937 randomEngine(randomSeed);

    std::uniform_int_distribution<int> randomIntDistribution(st, en);

    int value = randomIntDistribution(randomEngine);

    return value;
}

int ReversiAlgorithm::MoveAtRandom(std::vector<int> moves, int num, int color, int i){
    return board.move(moves[rand() % num],color);
}

int ReversiAlgorithm::playout(int color){
    int passCount = 0;
    int myColor = 3 - color;
    int oppColor = color;
    int num;

    int i = 0;

    while(passCount < 2){
        num = 0;
        std::vector<int> moves = getAvailableMoves(color, &num);

        if (num == 0) {
        //if there are no available moves, pass the turn.
            passCount++;
            continue;
        }

        if(passCount == 2) break;

        if (MoveAtRandom(moves, num, color, i++) > 0) passCount = 0;
        // color == 1 ? printf("White[@]\n"):printf("Black[O]\n");
        board.printb();
        //reverse turn color
        color = 3 - color;
    }

    if(count(*board.get_Board(myColor)) > count(*board.get_Board(oppColor))) return 1;
    else return 0;

}

ReversiAlgorithm::ReversiAlgorithm(){
    srand((unsigned int) time(NULL));
}

//--------------------------------
void printMoves(BitBoard moves){
    int i;
    for(i=0;i<64;i++){
        if(getBit(moves, i) == 1ull) printf("%d, ", i);
    }
    printf("\n");
}