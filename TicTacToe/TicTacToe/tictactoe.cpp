#include "tictactoe.h"

#include <iostream>
#include <conio.h>

using namespace std; 

void TicTacToe::ReDraw()
{
	system("CLS");
	cout << "-------------" << endl;
	cout << "Tic Tac Toe!!!" << endl;
	cout << "-------------" << endl << endl;
	m_current.Draw();
}

GameInstance TicTacToe::CurrentState()
{
	return m_current;
}

void TicTacToe::PlayNextAIMove()
{
	if (m_current.IsGameOver())
		return;

	m_current  = m_current.NextAIMove();
	ReDraw();
}

void TicTacToe::GetNextMoveByUser()
{
	if (m_current.IsGameOver())
		return;

	int position;
	while (true)
	{
		ReDraw();		
		cout << "Select board position from number 1 to 9:";
		cin >> position;
		if (position < 1 || position > 9 || m_current.IsNotEmpty(position)) {
			cout << "invalid position!!" << endl;
			_getch();
			continue;
		}
		break;
	}
	m_current = m_current.UpdateInstance(position);
	ReDraw();	
}