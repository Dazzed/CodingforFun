#include "tictactoe.h"

#include "iostream"
#include "vector"

using namespace std;

GameInstance::GameInstance()
{
	m_win = false;
	GridCellValue position[TotalGridCells] = { GridCellValue::Empty };
	InitializeGameInstance(position, true);
}

GameInstance::GameInstance(GridCellValue position[TotalGridCells], bool isPlayerXTurn)
{
	m_win = false;
	InitializeGameInstance(position, isPlayerXTurn);
}

void GameInstance::InitializeGameInstance(GridCellValue position[TotalGridCells], bool isPlayerXTurn)
{
	for (int i = 0; i < TotalGridCells; i++)
		m_position[i] = position[i];

	m_playerXTurn = isPlayerXTurn;
	ComputeScore();
}

bool GameInstance::IsNotEmpty(int position)
{
	if (m_position[position - 1] == Empty)
		return false;
	return true;
}

GameInstance GameInstance::UpdateInstance(int position)
{
	GameInstance res = *this;
	res.m_position[position - 1] = (m_playerXTurn) ? GridCellValue::X : GridCellValue::O;
	res.m_playerXTurn = !m_playerXTurn;
	ComputeScore();
	return res;
}

bool GameInstance::IsGameOver()
{
	if (m_win)
		return true; 

	for (int i = 0; i < TotalGridCells; i++)
		if (m_position[i] == GridCellValue::Empty)
			return false;
	return true;
}

void GameInstance::AllowedNextInstances(vector<GameInstance>& instances)
{
	GameInstance tmp;
	for (int i = 0; i < TotalGridCells; i++)
	{
		if (m_position[i] == GridCellValue::Empty)
		{
			tmp = *this;
			tmp.m_position[i] = (m_playerXTurn) ? GridCellValue::X : GridCellValue::O;
			tmp.m_playerXTurn = !m_playerXTurn;
			tmp.ComputeScore();
			instances.push_back(tmp);
		}
	}
}

int GameInstance::MinMax(int depth, bool needMax, int alpha, int beta, GameInstance& childWithMax)
{
	if (depth == 0 || IsGameOver())
	{
		m_minmaxscore = m_score;
		return m_score;
	}

	vector<GameInstance> nextMoves;
	AllowedNextInstances(nextMoves);
	for(GameInstance possibleInstance : nextMoves)
	{
		GameInstance tmp;
		int score = possibleInstance.MinMax(depth - 1, !needMax, alpha, beta, tmp);
		if (!needMax)
		{
			if (beta > score)
			{
				beta = score;
				childWithMax = possibleInstance;
			}
		}
		else
		{
			if (alpha < score)
			{
				alpha = score;
				childWithMax = possibleInstance;		
			}
		}

		if (alpha >= beta)
		{
			break;
		}
	}
	m_minmaxscore = needMax ? alpha : beta;
	return m_minmaxscore;
}

GameInstance GameInstance::NextAIMove()
{
	GameInstance ret;
	int LARGE_INTEGER = (int)pow(2, 20);
	MinMax(9, m_playerXTurn, -LARGE_INTEGER, LARGE_INTEGER, ret);
	return ret;
}

int GameInstance::ComputeScoreforCombo(GridCellValue position[WinComboLength])
{
	int countX = 0, countO = 0;
	for (int i = 0; i < WinComboLength; i++)
	{
		if (position[i] == GridCellValue::X)
			countX++;
		else if (position[i] == GridCellValue::O)
			countO++;
	}

	if (countO == 3 || countX == 3)
	{
			m_win = true;
	}

	int advantage = 1;
	if (countO == 0)
	{
		if (m_playerXTurn)
			advantage = 3;
		return (int)pow(10, countX) * advantage;
	}
	else if (countX == 0)
	{
		if (!m_playerXTurn)
			advantage = 3;
		return -(int)pow(10, countO) * advantage;
	}
	return 0;
}

void GameInstance::ComputeScore()
{	
	m_score = 0;

	int wincombo[][WinComboLength] = {
			{ 0, 1, 2 },
	     	{ 3, 4, 5 },
   			{ 6, 7, 8 },
			{ 0, 3, 6 },
			{ 1, 4, 7 },
			{ 2, 5, 8 },
			{ 0, 4, 8 },
			{ 2, 4, 6 }
		};
	
	GridCellValue position[WinComboLength];
	for (int i = 0; i < sizeof(wincombo) / sizeof(wincombo[0]); i++)
	{
		position[0] = m_position[wincombo[i][0]];
		position[1] = m_position[wincombo[i][1]];
		position[2] = m_position[wincombo[i][2]];
		m_score += ComputeScoreforCombo(position);
	}
}

void GameInstance::Draw()
{
	for (int i = 0; i < TotalGridCells; i++)
	{
		if (i % 3 == 0)
			cout << endl;
		switch (m_position[i]) {
		case GridCellValue::Empty:
			cout << " ";
			break;
		case GridCellValue::O:
			cout << "O";
			break;
		case GridCellValue::X:
			cout << "X";
			break;
		default:
			cout << "ERR";
		};

		if (i != 2 && i != 5 && i != 8)
			cout << "|";
	}
	cout << endl;
}