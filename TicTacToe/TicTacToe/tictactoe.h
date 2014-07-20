#ifndef _TICTACTOE
#define _TICTACTOE

#include<vector>

const int TotalGridCells = 9;
const int WinComboLength = 3;

enum GridCellValue {
	Empty = 0,
	X,
	O
};

//
// GameInstance 
//
// This class represents current board view.
// it contains information on all 9 boxes; whether they are
// empty, marked x or marked o.
// additionally it knows which player's turn it is now.
// 
class GameInstance {
private:
	GridCellValue m_position[TotalGridCells];
	bool m_playerXTurn;
	bool m_win;
	int m_score;
	int m_minmaxscore;
	int ComputeScoreforCombo(GridCellValue position[WinComboLength]);
	
public:
	GameInstance();
	GameInstance(GridCellValue position[TotalGridCells], bool isPlayerXTurn);
	
	void InitializeGameInstance(GridCellValue position[TotalGridCells], bool isPlayerXTurn);

	void Draw();
	void ComputeScore();
	int MinMaxScore() {
		return m_minmaxscore;
	}

	bool IsGameOver();

	bool IsNotEmpty(int position);
	GameInstance UpdateInstance(int position);

	void AllowedNextInstances(std::vector<GameInstance>& instances);
	int MinMax(int depth, bool needMax, int alpha, int beta, GameInstance& childWithMax);
	GameInstance NextAIMove();
};

class TicTacToe {
private:
	GameInstance m_current;
public:
	TicTacToe(){};
	GameInstance CurrentState();
	void PlayNextAIMove();
	void ReDraw();
	void GetNextMoveByUser();	
};

#endif