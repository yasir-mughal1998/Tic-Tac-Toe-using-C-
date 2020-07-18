#include<iostream>
#include"GameBoard.h"
using namespace std;

GameBoard::GameBoard()
{
	
}
void GameBoard::displayBoard()
{
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			cout << data[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void GameBoard::markBoard(char pos, char playerSymbol)
{
	if (isValidPosition(pos) && !isAlreadyMarked(pos))
	{
		if (pos == '1')
			data[0][0] = playerSymbol;

		else if (pos == '2')
			data[0][1] = playerSymbol;

		else if (pos == '3')
			data[0][2] = playerSymbol;

		else if (pos == '4')
			data[1][0] = playerSymbol;

		else if (pos == '5')
			data[1][1] = playerSymbol;

		else if (pos == '6')
			data[1][2] = playerSymbol;

		else if (pos == '7')
			data[2][0] = playerSymbol;

		else if (pos == '8')
			data[2][1] = playerSymbol;

		else if (pos == '9')
			data[2][2] = playerSymbol;

		validMovesCount = validMovesCount + 1;

	}
}		
void GameBoard::setGameStatus(GameStatus gs)
{
	gameStatus = gs;
}
GameStatus GameBoard::getGameStatus()
{
	return gameStatus;
}
bool GameBoard::isValidPosition(char pos)
{	
	if (pos >= '1' && pos <= '9')
	{
		return true;
	}
	return false;
}
bool GameBoard::isAlreadyMarked(char pos)
{
	if (data[(pos - 1 - '0') / 3][(pos - 1 - '0') % 3] == pos)
	{
		return false;
	}
	return true;
}
bool GameBoard::isWin()
{
	if (data[0][0] == data[0][1] && data[0][1] == data[0][2])
		return true;

	else if (data[1][0] == data[1][1] && data[1][1] == data[1][2])
		return true;

	else if (data[2][0] == data[2][1] && data[2][1] == data[2][2])
		return true;

	else if (data[0][0] == data[1][0] && data[1][0] == data[2][0])
		return true;

	else if (data[0][1] == data[1][1] && data[1][1] == data[2][1])
		return true;

	else if (data[0][2] == data[1][2] && data[1][2] == data[2][2])
		return true;

	else if (data[0][0] == data[1][1] && data[1][1] == data[2][2])
		return true;

	else if (data[0][2] == data[1][1] && data[1][1] == data[2][0])
		return true;

	else
		return false;
	
}
int GameBoard::getValidMovesCount()
{
	return validMovesCount;
}