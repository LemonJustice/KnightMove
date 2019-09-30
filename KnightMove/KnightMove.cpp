// KnightMove.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <iomanip>
using namespace std;

//Allows for easier testing of different sizes without messing with vectors and dynamic memory.
const int BOARD_LENGTH = 5;
int attempts = 0;

bool moveKnight(int board[BOARD_LENGTH][BOARD_LENGTH], int row, int col, int move);
bool isLegitimateMove(int board[BOARD_LENGTH][BOARD_LENGTH], int row, int col, int moveType);
void printBoard(int board[BOARD_LENGTH][BOARD_LENGTH]);

int main()
{
	//making the array that holds all values on the board
	int board[BOARD_LENGTH][BOARD_LENGTH] = { 0 };
	//alreadyTried prevents the same move being made ag
	moveKnight(board, 0, 0, 1);
	printBoard(board);
	system("pause");
}


bool moveKnight(int board[BOARD_LENGTH][BOARD_LENGTH], int row, int col, int move) {
	board[row][col] = move;
	bool success = false;
	cout << ++attempts << ", " << move << endl;
	printBoard(board);

	if (isLegitimateMove(board, row, col, 1)) { // move 1
		cout << "MoveType: 1" << endl;
		success = moveKnight(board,   row - 2, col + 1, move + 1);
		if (!success) 
			board[row - 2][col + 1] = 0;
	}
	if (isLegitimateMove(board, row, col, 2)) { // move 2
		cout << "MoveType: 2" << endl;
		success = moveKnight(board,   row - 1, col + 2, move + 1);
		if (!success)
			board[row - 1][col + 2] = 0;
	}
	if (isLegitimateMove(board, row, col, 3)) { // move 3
		cout << "MoveType: 3" << endl;
		success = moveKnight(board,   row + 1, col + 2, move + 1);
		if (!success)
			board[row + 1][col + 2] = 0;
	}
	if (isLegitimateMove(board, row, col, 4)) { // move 4
		cout << "MoveType: 4" << endl;
		success = moveKnight(board,   row + 2, col + 1, move + 1);
		if (!success)
			board[row + 2][col + 1] = 0;
	}
	if (isLegitimateMove(board, row, col, 5)) { // move 5
		cout << "MoveType: 5" << endl;
		success = moveKnight(board,   row + 2, col - 1, move + 1);
		if (!success)
			board[row + 2][col - 1] = 0;
	}
	if (isLegitimateMove(board, row, col, 6)) { // move 6
		cout << "MoveType: 6" << endl;
		success = moveKnight(board,   row + 1, col - 2, move + 1);
		if (!success)
			board[row + 1][col - 2] = 0;
	}
	if (isLegitimateMove(board, row, col, 7)) { // move 7
		cout << "MoveType: 7" << endl;
		success = moveKnight(board,   row - 1, col - 2, move + 1);
		if (!success)
			board[row - 1][col - 2] = 0;
	}
	if (isLegitimateMove(board, row, col, 8)) { // move 8
		cout << "MoveType: 8" << endl;
		success = moveKnight(board,   row - 2, col - 1, move + 1);
		if (!success) 
			board[row - 2][col - 1] = 0;
	}
	cout << "Backing Up" << endl;
	if (move == BOARD_LENGTH * BOARD_LENGTH) {
		return true;
	}
	else
		return false;
}

//Separating the conditional to make the recursive function easier to read.
bool isLegitimateMove(int board[BOARD_LENGTH][BOARD_LENGTH], int row, int col, int moveType) {
	switch (moveType) {
	case 1:
		if (row - 2 < BOARD_LENGTH && row - 2 >= 0
			&& col + 1 < BOARD_LENGTH && col + 1 >= 0
			&& board[row - 2][col + 1] == 0) {
			return true;
		}
		return false;
		break;
	case 2:
		if (row - 1 < BOARD_LENGTH && row - 1 >= 0
			&& col + 2 < BOARD_LENGTH && col + 2 >= 0
			&& board[row - 1][col + 2] == 0) {
			return true;
		}
		return false;
		break;
	case 3:
		if (row + 1 < BOARD_LENGTH && row + 1 >= 0
			&& col + 2 < BOARD_LENGTH && col + 2 >= 0
			&& board[row + 1][col + 2] == 0) {
			return true;
		}
		return false;
		break;
	case 4:
		if (row + 2 < BOARD_LENGTH && row + 2 >= 0
			&& col + 1 < BOARD_LENGTH && col + 1 >= 0
			&& board[row + 2][col + 1] == 0) {
			return true;
		}
		return false;
		break;
	case 5:
		if (row + 2 < BOARD_LENGTH && row + 2 >= 0
			&& col - 1 < BOARD_LENGTH && col - 1 >= 0
			&& board[row + 2][col - 1] == 0) {
			return true;
		}
		return false;
		break;
	case 6:
		if (row + 1 < BOARD_LENGTH && row + 1 >= 0
			&& col - 2 < BOARD_LENGTH && col - 2 >= 0
			&& board[row + 1][col - 2] == 0) {
			return true;
		}
		return false;
		break;
	case 7:
		if (row - 1 < BOARD_LENGTH && row - 1 >= 0
			&& col - 2 < BOARD_LENGTH && col - 2 >= 0
			&& board[row - 1][col - 2] == 0) {
			return true;
		}
		return false;
		break;
	case 8:
		if (row - 2 < BOARD_LENGTH && row - 2 >= 0
			&& col - 1 < BOARD_LENGTH && col - 1 >= 0
			&& board[row - 2][col - 1] == 0) {
			return true;
		}
		return false;
		break;
	}
}

void printBoard(int board[BOARD_LENGTH][BOARD_LENGTH]) {
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_LENGTH; j++) {
			if (board[i][j] == 0)
				cout << setw(3) << "*";
			else
				cout << setw(3) << board[i][j];
		}
		cout << endl;
	}
	cout << "\n\n";
}





