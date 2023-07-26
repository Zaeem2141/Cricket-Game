#include "Menu.h"
using namespace std;

void welcomeBoard()
{
	cout << "\t\t\t\t\t\t" << (char)3 << (char)3 << "Welcome" << (char)3 << (char)3 << endl;
	cout << "Select an option (1-3) : " << endl;
	cout << "\t 1.   Play " << endl;
	cout << "\t 2.   Rules " << endl;
	cout << "\t 3.   Exit " << endl << endl;
}

int selectChoice()
{
	int option;
	cout << "Enter your choice : ";
	cin >> option;
	return option;
}

void menu(int option)
{
	switch (option)
	{
	case 0:
	{
		cout << "Thanks for playing " << endl;
		exit(0);
		break;
	}
	case 1:
	{
		break;
	}
	case 2:
	{
		cout << "\t\t\t\tRules : " << endl;
		cout << "1.Its a five over match " << endl;
		cout << "2.It comprises of 5  teams " << endl;
		cout << "3.Each team consists of 11 players " << endl;
		cout << "4.Playing will be decided on the basis of toss " << endl;
		cout << "5.All international cricket rules will be applicable " << endl;
		cout << endl << endl;
		break;
	}
	case 3:
	{
		cout << "Thanks for playing " << endl;
		exit(0);
		break;
	}
	default:
	{
		cout << "Sorry ! Its A Wrong choice " << endl;
	}
	};
}

void displayTeams()
{
	cout << "Select your team from the following : " << endl;
	cout << "1.   Pakistan" << endl;
	cout << "2.   Australia" << endl;
	cout << "3.   New Zealand" << endl;
	cout << "4.   Zimbabwe" << endl;
	cout << "5.   Sri Lanka" << endl;
}

int selectTeam()
{
	int option;
	cout << "Your Team : ";
	cin >> option;
	return option;
}

void displayPlayers(int choice)
{
	string totalPlayers[80];

	ifstream in("TeamPlayers.txt", ios::in | ios::app | ios::binary);
	for (int i = 0; i < 80; i++)
	{
		in >> totalPlayers[i];
	}

	int a = 0;

	if (choice == 1)
	{
		for (int i = 0; i < 16; i++)
		{
			cout << i + 1 << ". " << totalPlayers[i] << endl;
		}
	}
	else if (choice == 2)
	{
		for (int i = 16; i < 32; i++)
		{
			cout << a + 1 << ". " << totalPlayers[i] << endl;
			a++;
		}
	}

	else if (choice == 3)
	{
		for (int i = 32; i < 48; i++)
		{
			cout << a + 1 << ". " << totalPlayers[i] << endl;
			a++;
		}
	}

	else if (choice == 4)
	{
		for (int i = 48; i < 64; i++)
		{
			cout << a + 1 << ". " << totalPlayers[i] << endl;
			a++;
		}
	}

	else if (choice == 5)
	{
		for (int i = 64; i < 80; i++)
		{
			cout << a + 1 << ". " << totalPlayers[i] << endl;
			a++;
		}
	}
}

int selectPlayer()
{
	int choice;
	cin >> choice;
	while (choice <= 0 || choice > 16)
	{
		cout << "Enter again (1-16): ";
		cin >> choice;
	}
	return choice;
}

bool doToss()
{
	bool flag = false;
	cout << "Heads or Tails?" << endl;
	cout << "    1. Heads" << endl;
	cout << "    2. Tails" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	system("CLS");
	Driver d;
	d.setToss();
	if ((d.getToss() == "Heads" && choice == 1) || (d.getToss() == "Tails" && choice == 2))
	{
		flag = true;
		cout << "Congratulations! You won the toss." << endl;
		cout << "Would you like to bat or bowl?" << endl;
		cout << "    1. Bat" << endl;
		cout << "    2. Bowl" << endl;
		cout << "Your choice: ";
		cin >> choice;
		system("CLS");

		if (choice == 2)
		{
			flag = false;
		}
	}
	else
	{
		cout << "Sorry, you lost the toss, the opponent has choosen to bat." << endl << endl;
	}
	return flag;
}