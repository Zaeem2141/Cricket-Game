#pragma once
#include <iostream>
#include <string>
#include "Team.h"

class Player
{
private:
	string playerId;
public:
	Player();
	void setPlayerId(string);
	string getPlayerId();
	void display();
};

