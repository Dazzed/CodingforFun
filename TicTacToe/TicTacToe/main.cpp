#include<iostream>
#include<string>
#include<conio.h>
#include "tictactoe.h"

using namespace std;

int main(int argc, char** argv)
{
	int firstPlayer;
	char playAgain = false;
	TicTacToe* Game;

	while (true)
	{
		system("CLS");
		cout << "-------------" << endl;
		cout << "Tic Tac Toe!!!" << endl;
		cout << "-------------" << endl << endl;
		cout << "Who goes first? Press 1 for Computer Press 2 for User:";
		cin >> firstPlayer;

		Game = new TicTacToe();
		while (!Game->CurrentState().IsGameOver())
		{
			if (firstPlayer == 1) {
				Game->PlayNextAIMove();
				Game->GetNextMoveByUser();
				
			}
			else if (firstPlayer == 2) {				
				Game->GetNextMoveByUser();
				Game->PlayNextAIMove();
			}
			else {
				cout << "Invalid Input!!";
				_getch();
				break;
			}
		}

		if (Game->CurrentState().MinMaxScore() < -300) {
			cout << " \n\nO wins!\n\n" << endl;
		}
		else if ((Game->CurrentState().MinMaxScore() > 300)) {
			cout << " \n\nX wins!\n\n" << endl;
		}
		else {
			cout << " \n\nIt's a Tie!\n\n" << endl;
		}
		delete Game;
		Game = nullptr;
		cout << "Play Again? (y/n):";
		cin >> playAgain;

		if (playAgain != 'y')
			break;
	} 
	return 0;
}