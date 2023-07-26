#include "Team.h"
#include <string>
#include <cstdlib>

Team::Team()
{
	teamId = "\0";
	wickets = 0;
	balls = 0;
	score = 0;
}

void Team::setTeamId(string id)
{
	teamId = id;
}

void Team::setWickets(int w)
{
	wickets = w;
}

void Team::setBalls(int b)
{
	balls = b;
}

void Team::setStatusWin(int flag)
{
	statusWin = flag;
}

void Team::decisionOfGame1()
{
	if (statusWin == 0)
	{
		cout << "\nThe opponent have chased the score successfully." << endl;
		cout<<	"You have lost the match." << endl;
	}
	if (statusWin == 1)
	{
		cout << "\nThe opponent have not chased the target unfortunately." << endl;
		cout << "Congratulations! You have won the match." << endl;
	}
	if(statusWin==2)
	{
		cout << "The match has been drawn." << endl;
	}
}

void Team::decisionOfGame2()
{
	if (statusWin == 0)
	{
		cout << "\nYou have chased the target successfully." << endl;
		cout << "Congratulations! You have won the match." << endl;
	}
    if (statusWin == 1)
	{
		cout << "\nYou have not chased the target unfortunately." << endl;
		cout << "You have lost the match." << endl;
	}
	if(statusWin==2)
	{
		cout << "The match has been drawn." << endl;
	}
}

string Team::getTeamId()
{
	return teamId;
}

int Team::getBalls()
{
	return balls;
}

int Team::getScore()
{
	return score;
}

int Team::getWickets()
{
	return wickets;
}

int Team::getStatusWin()
{
	return statusWin;
}

void Team::display()
{
	//cout << "\t\t\t\t    Team name: " << teamId << endl;
	cout << "\t\t\t\t    Current Score is: " << score << endl;
	cout << "\t\t\t\t    Wickets remaining: " << wickets << endl;
	cout << "\t\t\t\t    Balls Left: " << balls << endl;
}
