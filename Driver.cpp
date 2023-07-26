#include "Driver.h"
#include <cstdlib>
void Driver::setToss()
{
	int flag;
	srand(static_cast<unsigned>(time(0)));
	flag = rand() % 2;
	if (flag == 0)
	{
		toss = "Heads";
	}
	if (flag == 1)
	{
		toss = "Tails";
	}
}

string Driver::getToss()
{
	return toss;
}

void Driver::setIsStrike(int choice)
{
	if (choice == 1)
	{
		isStrike = true;
	}
	else
	{
		isStrike = false;
	}
}

void Driver::setBallLabel(int len, int wid, int height, int deviation)
{
	if (len > pitchLength)
	{
		ballLabel = "NoBall";
	}
	else if (wid > ballWidth)
	{
		ballLabel = "Wide";
	}
	else if (height <= ballHeight && deviation <= 1 && deviation >= -1)
	{
		ballLabel = "Out";
	}
	else if (height > ballHeight)
	{
		ballLabel = "Bouncer";
	}
	else if (deviation <= 5 && deviation >= -5)
	{
		ballLabel = "Spin";
	}
	else
	{
		ballLabel = "Normal";
	}
}

void Driver::drive(Team& t2)
{
	t2.balls--;

	if (ballLabel == "NoBall")
	{
		int temp;
		t2.balls += 1;
		t2.score += 1;
		cout << "\t\t\t\tIts a No BAll , Bowler foot is out of range " << endl;
		if (isStrike == true)
		{
			cout << "Played " << endl;
			temp = rand() % 3 + 4;
			if (temp == 4)
			{
				cout << "\t\t\t\tGorgeous shot " << (char)3 << " 4 runs !" << endl;
			}
			else if (temp == 6)
			{
				cout << "\t\t\t\tTermendous shot " << (char)3 << " 6 runs !" << endl;
			}
			while (temp == 5)
			{
				temp = rand() % 3 + 4;
				if (temp == 4)
				{
					cout << "\t\t\t\tGorgeous shot " << (char)3 << " 4 runs !" << endl;
				}
				else if (temp == 6)
				{
					cout << "\t\t\t\tTermendous shot " << (char)3 << " 6 runs !" << endl;
				}
			}
			t2.score += temp;
		}
		else
		{
			cout << "\t\t\t\t\tNot Played " << endl;
			t2.score += 0;
		}
	}
	else if (ballLabel == "Wide")
	{
		if (isStrike == true)
		{
			cout << "\t\t\t\tOut of Line , Its a WIDE ball But Played  " << endl;
			cout << " \t\t\t\t\t4 runs " << endl;
			t2.score += 4;
		}
		else
		{
			cout << "\t\t\t\tOut of Line , Its a WIDE ball " << endl;
			t2.score += 1;
			t2.balls += 1;
		}
	}
	else if (ballLabel == "Bouncer")
	{
		
		if (isStrike == true)
		{
			cout << "\t\t\t\tWhat a Bouncer But greatly Played and 6 runs " << endl;
			t2.score += 6;
		}
		else
		{
			cout << "\t\t\t\tNice Duck " << endl;
			t2.score += 0;
		}
	}
	else if (ballLabel=="Spin" || ballLabel=="Normal")
	{
		int temp;
		if (isStrike == true)
		{
			temp = rand() % 7;
			if (temp == 0)
			{
				cout << "\t\t\t\tStriked but not played well" << endl;
			}
			else if (temp == 1||temp==2)
			{
				cout << "\t\t\t\tWhat a run " << endl;
			}
			else if (temp == 4)
			{
				cout << "\t\t\t\tGorgeous shot  4 runs !" << endl;
			}
			else if (temp == 6)
			{
				cout << "\t\t\t\tTermendous shot  6 runs !" << endl;
			}
			while (temp == 3 || temp == 5)
			{
				temp = rand() % 7;
				if (temp == 0)
				{
					cout << "\t\t\t\tStriked but not played well" << endl;
				}
				else if (temp == 1 || temp == 2)
				{
					cout << "\t\t\tWhat a run " << endl;
				}
				else if (temp == 4)
				{
					cout << "\t\t\t\tGorgeous shot  4 runs !" << endl;
				}
				else if (temp == 6)
				{
					cout << "\t\t\t\tTermendous shot  6 runs !" << endl;
				}
			}
			t2.score += temp;
		}
		else
		{
			cout << "\t\t\t\tNo strike " << endl;
			t2.score += 0;
		}
	}
	else if (ballLabel == "Out")
	{
		t2.score += 0;
		t2.wickets -= 1;
		if (isStrike == true)
		{
			cout << "\t\t\t\tThat was catch Out" << endl;
		}
		else
		{
			cout << "\t\t\t\tThat was Wicket Out." << endl;
		}
	}
}

void Driver::displayDriver()
{
	cout << "\t\t\t\t    Ball Label is: " << ballLabel << endl;
	if (isStrike == true)
	{
		cout << "\t\t\t\t    Strike flag= True" << endl;
	}
	else
	{
		cout << "\t\t\t\t    Strike flag= False" << endl;
	}
}

bool Driver::getIsStrike()
{
	return isStrike;
}

string Driver::getBallLabel()
{
	return ballLabel;
}

int Driver::randomScoreGenerator(int t)
{
	int temp = (rand() % t) + 5;
	return temp;
}