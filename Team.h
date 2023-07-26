#pragma once
#include <iostream>
using namespace std;

class Team
{
private:
	string teamId;
	int wickets;
	int balls;
	int score;
	int statusWin;
public:
	Team();
	void setTeamId(string);
	void setWickets(int);
	void setBalls(int);
	void setStatusWin(int);
	string getTeamId();
	int getBalls();
	int getWickets();
	int getScore();
	int getStatusWin();
	void decisionOfGame1();
	void decisionOfGame2();
	void display();
	friend class Driver;
};