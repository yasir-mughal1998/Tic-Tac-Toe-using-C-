enum PlayerTurn {FIRST_PLAYER=1,SECOND_PLAYER=2};
enum GameStatus {DRAW,WIN,IN_PROGRESS};

class GameBoard
{
private:
	char data[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
	GameStatus gameStatus = IN_PROGRESS;
	int validMovesCount = 0;
public:
	GameBoard();
	void displayBoard();
	void markBoard(char pos, char playerSymbol);
	bool isValidPosition(char pos);
	bool isAlreadyMarked(char pos);
	bool isWin();
	int getValidMovesCount();
	GameStatus getGameStatus();
	void setGameStatus(GameStatus gs);
};
