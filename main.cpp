/*
Roll No: BCSF20M032
Roll No: BCSF20M042
Roll No: BCSF20M044
 Section: CS_MORNING
 */

#include "Team.h"
#include "Driver.h"
#include "menu.h"
#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int choice, choice1,g,f;
	do
	{
		choice = choice1 = 0;
		welcomeBoard();
		choice = selectChoice();
		system("CLS");
		menu(choice);
		if (choice == 2)
		{
			cout << "1. Go to main menu " << endl;
			cout << "0. Exit " << endl;
			choice1 = selectChoice();
			system("CLS");
			if (choice1 == 0)
			{
				menu(choice1);
			}
		}
		else if (choice == 3)
		{
			exit(0);
		}

	} while (choice1 == 1);

	string teams[5];
	teams[0] = "Pakistan";
	teams[1] = "Australia";
	teams[2] = "New Zealand";
	teams[3] = "Zimbabwe";
	teams[4] = "Sri Lanka";

	displayTeams();
	choice = selectChoice();
	system("CLS");

	Team t1;           // Team 1
	t1.setTeamId(teams[choice - 1]);
	t1.setWickets(10);
	t1.setBalls(5);
	cout << "Your Team is: " << t1.getTeamId()<<endl;

	string totalPlayer[80];
	ifstream in("TeamPlayers.txt", ios::in | ios::app | ios::binary);
	for (int i = 0; i < 80; i++)
	{
		in >> totalPlayer[i];
	}

	displayPlayers(choice);
	Player p[11];            //Team of 11 Players

	cout << "Enter the number to select the relevant player." << endl;
	int temp, arr[11] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		if (choice == 1)
		{  
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp=selectPlayer();
					if (i != 1)
					{
						j=0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[temp - 1]);
		}
		else if (choice == 2)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[16 + (temp - 1)]);
		}
		else if (choice == 3)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[32 + (temp - 1)]);
		}
		else if (choice == 4)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[48 + (temp - 1)]);
		}
		else if (choice == 5)
		{
			cout << "Player " << i + 1 << ": ";
			temp = selectPlayer();
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == temp)
				{
					cout << "Already taken. Enter again: ";
					temp = selectPlayer();
					if (i != 1)
					{
						j = 0;
						j--;
					}
					else
					{
						j--;
					}
				}
			}
			arr[i] = temp;
			p[i].setPlayerId(totalPlayer[64 + (temp - 1)]);
		}
	}

	system("CLS");
	cout << endl << "Here is your selected team players: " << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << i + 1 << " : ";
		p[i].display();
	}

	char flag;
	int id, position;

	do {
		cout << "Do you want to modify the batting order? (y/n)." << endl;
		cin >> flag;
		while (flag != 'y' && flag != 'n')
		{
			cout << "Enter correct choice: ";
			cin >> flag;
		}

		if (flag == 'y')
		{
			Player temp;
			cout << "Please enter the id number of the player which needs to be modified:";
			cin >> id;
			cout << "Please specify the position number in the team to insert the player: ";
			cin >> position;

			temp.setPlayerId(p[position - 1].getPlayerId());
			p[position - 1].setPlayerId(p[id - 1].getPlayerId());
			p[id - 1].setPlayerId(temp.getPlayerId());

		}
		else
		{
			break;
		}
	} while (flag == 'y');

	system("CLS");
	cout << endl << "Here is Batting order of players: " << endl;

	for (int i = 0; i < 11; i++)
	{
		cout << i + 1 << " : ";
		p[i].display();
	}


	bool flag1;
	flag1 = doToss();
	cout << "\t\t\t"<<(char)3 << (char)3<<"___________Now, Let's Start your Game_____________" << (char)3 << (char)3<<endl<<endl;
	Driver d;
	int totalBalls = t1.getBalls();

	switch (flag1)
	{
		// For Bowling First
	//"_________________________________________________________________________________________"
	//"_________________________________________________________________________________________"
	case false:
		int length, width, height, deviation;

		int temp;

		for (int i = 1; i <= totalBalls; i++)
		{
		    	cout << "\t\t\t\t   " << t1.getTeamId() << " Is bowling " << endl;
			cout << "\n###__________________________________________________________________###" << endl;		
			cout << "Enter ball Length to be delivered (1-50). (>50 No ball): ";
			cin >> length;
			cout << "Enter ball width to be delivere (1-5). (>5 Wide): ";
			cin >> width;
			cout << "Enter ball height to be delivered (1-5). (>5 Bouncer):  ";
			cin >> height;
			cout << "Enter ball deviation to be delivered:(-5, 5). (Otherwise Normal):  ";
			cin >> deviation;
			if (choice == 5)
			{
				cout <<endl<< "\t\t\t\t  Team playing : " << teams[choice - 2] << endl<<endl;
				 }
			else 
			{
				cout <<endl<< "\t\t\t\t  Team playing  : " << teams[choice] << endl << endl;
			}
			cout << endl << "\t\t\t\t" << (char)3 << "Current  Ball Statistics" << (char)3 << endl<<endl;
			if (d.getBallLabel() == "NoBall" || (d.getBallLabel() == "Wide" && d.getIsStrike() != true))
			{
				i--;
			}

			d.setBallLabel(length, width, height, deviation);
			temp = rand() % 2;
			d.setIsStrike(temp);
			d.drive(t1);
			cout << "\t\t\t###__________________________________________###" << endl;
			d.displayDriver();
			cout << "\t\t\t###__________________________________________###" << endl;
			t1.display();
			system("pause");
			cout<<endl << "Press any Key to continue !!!" << endl;
			system("CLS");
			if (i == totalBalls)
			{
				cout <<endl << "Target given to your team is: " << t1.getScore() + 1<< endl;
			}


		}
		f = d.randomScoreGenerator(t1.getScore());
		if (f > t1.getScore())
		{
			t1.setStatusWin(0);
			cout << "Your team score is: " << f << endl;

		}
		else if (f < t1.getScore())
		{
			t1.setStatusWin(1);
			cout << "Your team score is: " << f << endl;

		}
		else if (f == t1.getScore())
		{
			t1.setStatusWin(2);
			cout << "Your team score is: " << f << endl;
		}
		t1.decisionOfGame2();
		break;
		// For Batting First
	//"_________________________________________________________________________________________"
	//"_________________________________________________________________________________________"
	case true:

		int len, wid, hei, dev;
		int tBalls = t1.getBalls();

		int temp1;
		int strike;

		for (int i = 1; i <= tBalls; i++)
		{
			len = rand() % 53;
			wid = rand() % 8;
			hei = rand() % 7;
			dev = rand() % 15 - 5;

			cout << "\t\t\t\t  " << t1.getTeamId() << " Is batting " << endl<<endl;

			if (choice == 5)
			{
				cout << endl << "\t\t\t\t  Team Bowling : " << teams[choice - 2] << endl << endl;
			}
			else
			{
				cout << endl << "\t\t\t\t  Team Bowling  : " << teams[choice] << endl << endl;
			}
			cout << "\nEnter 1 to Strike or Enter 0 to skip: ";
			cin >> strike;
			

			cout << endl << "\t\t\t\t" << (char)3 << "Current  Ball Statistics" << (char)3 << endl << endl;
			cout << "\t\t\t###__________________________________________________________________###" << endl;
			cout << "\t\t\t\tBall Length= " << len << endl;
			cout << "\t\t\t\tBall Width= " << wid << endl;
			cout << "\t\t\t\tBall Height= " << hei << endl;
			cout << "\t\t\t\tAngle of Deviation= " << dev << endl;

			cout << "\t\t\t\t###__________________________________________###" << endl<<endl;
			d.setIsStrike(strike);
			d.setBallLabel(len, wid, hei, dev);

			if (d.getBallLabel() == "NoBall" || (d.getBallLabel() == "Wide" && d.getIsStrike() != true))
			{
				i--;
			}

			d.drive(t1);
			cout<<endl << "\t\t\t\t###__________________________________________###" << endl;
			d.displayDriver();
			cout << "\t\t\t\t###__________________________________________###" << endl;
			t1.display();
			system("pause");
			cout << endl<< "Press any Key to continue !!!" << endl;
			system("CLS");

			if (i == tBalls)
			{
				cout << endl << "Target given to opponent team is: " << t1.getScore() + 1 << endl;;
			}
		}
		 g = d.randomScoreGenerator(t1.getScore());
		if(g > t1.getScore())
		{
			t1.setStatusWin(0);
			cout << "Opponent team score is: " << g << endl;

		}
		else if(g < t1.getScore())
		{
			t1.setStatusWin(1);
			cout << "Opponent team score is: " << g << endl;

		}
		else if (g == t1.getScore())
		{
			t1.setStatusWin(2);
			cout << "Opponent team score is: " << g << endl;
		}
		t1.decisionOfGame1();
		break;
	}
	return 0;
}