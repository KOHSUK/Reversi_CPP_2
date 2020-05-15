#pragma once
#include "Board.h"
#include "ReversiMoveSearcher.h"
#include <vector>
#define START_LEN 68
#define MYTURN_LEN 5
#define OPPONENTSTURN_LEN 6
#define MYTURN 1
#define OPPONENTSTURN 0
#define CONTINUE 0
#define WIN 1
#define LOSE 2
#define DRAW 3

enum class MessageType{
	NONE = -1,
	GameStarts_OpponentsTurn = 0,
	GameStarts_MyTurn = 1,
	OpponentsMove = 2,
	MyMove = 3,
	Win = 4,
	Lose = 5,
	Draw = 6
};

class Reversi
{
private:
	ReversiMoveSearcher searcher;

	int currentTurn = 0;

	int myColor;

	int opponentsColor;

	void applyOpponentsMove(char* move);

	int setBoard(char * cBoard);

public:

	char * getNextMove();

	MessageType processMessage(char* message);

	Reversi(char* cBoard);

	Reversi();

	~Reversi();
};

