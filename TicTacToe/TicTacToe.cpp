#include"GameBoard.h"
#include"TicTacToe.h"
#include<iostream>
using namespace std;

void TicTacToe::playGame()
{
	GameBoard gameBoard;
	PlayerTurn playerTurn = FIRST_PLAYER;
	char choice[3];
	cout << "Enter player 1 symbol: ";
	cin >> choice[FIRST_PLAYER];
	cout << "Enter player 2 symbol: ";
	cin >> choice[SECOND_PLAYER];
	while (gameBoard.getGameStatus() == IN_PROGRESS && gameBoard.getValidMovesCount() < 9 )
	{
		char temp;
		gameBoard.displayBoard();
		do
		{
			cout << "Player " << playerTurn << " Turn:Enter Cell # ";
			cin >> temp;
		} while(gameBoard.isValidPosition(temp) == false || gameBoard.isAlreadyMarked(temp) == true );
		gameBoard.markBoard(temp, choice[playerTurn]);
		if (gameBoard.isWin())
		{
			gameBoard.setGameStatus(WIN);
			cout << "Player " << playerTurn << " win"<<endl;
		}
		if (playerTurn == FIRST_PLAYER)
		{
			playerTurn = SECOND_PLAYER;
		}
		else
		{
			playerTurn = FIRST_PLAYER;
		}

	}
	if (gameBoard.getGameStatus() == IN_PROGRESS)
	{
		cout << "Draw" << endl;
	}
}