#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;

#define BOARD_HEIGHT 10
#define BOARD_WIDTH 5
#define BLOCK_SIZE 5

bool bRunning;
enum eDirection{STOP = 0, LEFT, RIGHT, DOWN};
eDirection direction[BOARD_HEIGHT*BOARD_WIDTH];

//7 One-Sided Tetrominoes: I, J, L, O, S, T, Z
char Piece[7/*Tetromino*/][4/*Rotation*/][5/*Vertical*/][5/*Horizontal*/]{
	//I
	{
		{
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },	
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	//J
	{
		{
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 1 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}

	},

	//L
	{
		{
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	//O
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	//S
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	//T
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0,	1, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	//Z
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	}
};

int yMonoPiece[BOARD_HEIGHT*BOARD_WIDTH];
int xMonoPiece[BOARD_HEIGHT*BOARD_WIDTH];
int piecesCount;
int board[BOARD_HEIGHT][BOARD_WIDTH];

int countClearedLine;
bool clearedLine;

void Initialize() {
	bRunning = true;
	memset(yMonoPiece, -1, sizeof(yMonoPiece));
	memset(xMonoPiece, -1, sizeof(xMonoPiece));
	memset(board, -1, sizeof(board));

	piecesCount = 1;
	direction[0] = DOWN;
	yMonoPiece[0] = 0;
	xMonoPiece[0] = BOARD_WIDTH / 2;

	countClearedLine = 0;
	clearedLine = false;
}

void Start() {
	if (direction[piecesCount-1] != STOP) return;
	piecesCount++;
	direction[piecesCount - 1] = DOWN;
	yMonoPiece[piecesCount - 1] = 0;
	xMonoPiece[piecesCount - 1] = BOARD_WIDTH / 2;

	clearedLine = false;
}

void PollKey() {
	if (_kbhit()) {
		switch (_getch()) {
		//case 0x50:
		//	direction = DOWN;
		//	break;

		case 0x4b:
			direction[piecesCount - 1] = LEFT;
			break;

		case 0x4d:
			direction[piecesCount - 1] = RIGHT;
			break;

		default:
			break;
		}
	}
}

void Update() {
	//stop the piece when (they arrived at the Board Down-Bar) || (they arrived one piece up at the stacked mono piece)
	if ( (yMonoPiece[piecesCount - 1] == BOARD_HEIGHT - 1)
		|| (board[yMonoPiece[piecesCount - 1]+1][xMonoPiece[piecesCount - 1]] == 1) ) {
		direction[piecesCount - 1] = STOP;
		board[ yMonoPiece[piecesCount-1] ][ xMonoPiece[piecesCount-1] ] = 1;
	}
	//stop moving left/right when the monopiece is at the edge of the board
	else if (xMonoPiece[piecesCount - 1] == 0 || xMonoPiece[piecesCount - 1] == BOARD_WIDTH - 1)
		direction[piecesCount - 1] = DOWN;

	//if monoPieces fill the whole horizontal line, clear the line
	for (int j = BOARD_HEIGHT - 1; j >= 0; --j) {
		int fullLine = 0;
		for (int i = 0; i < BOARD_WIDTH; ++i) {
			if (board[j][i] == 1)
				++fullLine;
			if (fullLine == BOARD_WIDTH) {
				++countClearedLine;
				clearedLine = true;
				for (int k = 0; k < BOARD_WIDTH; ++k)//Fuck!!!!!!! ++i -> ++k 
					board[j][k] = -1;
			}
		}

		//pull the (j-1)th Line up to (j)th Line
		if (clearLine) {
			for(int)
		}
	}

	switch (direction[piecesCount - 1]) {
	case DOWN:
		++yMonoPiece[piecesCount - 1];
		break;

	case LEFT:
		--xMonoPiece[piecesCount - 1];
		direction[piecesCount - 1] = DOWN;
		break;

	case RIGHT:
		++xMonoPiece[piecesCount - 1];
		direction[piecesCount - 1] = DOWN;
		break;

	default:
		break;
	}
}	

void Draw() {
	system("cls");

	//print out countClearedLine
	cout << "countClearedLine: " << countClearedLine << endl;

	//Board Up-Bar
	for (int i = 0; i < BOARD_WIDTH+2; ++i)
		cout << '#';
	cout << endl;

	for (int j = 0; j < BOARD_HEIGHT; ++j) {
		//Board Left-Bar
		cout << '#';

		for (int i = 0; i < BOARD_WIDTH; ++i) {
			//print out the stacked mono piece on the board
			if (board[j][i] == 1)	cout << 'O';
	
			else {
				//print out the moving mono piece 
				if (yMonoPiece[piecesCount - 1] == j && xMonoPiece[piecesCount - 1] == i) {
					cout << 'O';
				}
				else
					cout << ' ';
			}
		}

		//Board Right-Bar
		cout << '#' << endl;
	}

	//Board Down-Bar
	for (int i = 0; i < BOARD_WIDTH+2; ++i)
		cout << '#';
	cout << endl;
}

int main() {
	Initialize();

	while (bRunning) {
		Start();
		PollKey();
		Update();
		Draw();
		Sleep(100);
	}

	return 0;
}