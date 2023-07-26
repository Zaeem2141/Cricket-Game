#pragma once
#include <string>
#include "Team.h"
class Driver
{
private:

	string toss;
	string ballLabel;
	bool isStrike;
	const int pitchLength = 50;
	const int ballWidth = 5;
	const int ballHeight = 6;
	const int angleDeviation = 90;

public:

	void setToss();
	string getToss();
	void setIsStrike(int);
	void setBallLabel(int, int, int, int);
	void drive(Team&);
	void displayDriver();
	bool getIsStrike();
	string getBallLabel();
	int randomScoreGenerator(int);
};

