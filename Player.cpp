#include "Player.h"

Player::Player()
{
	playerId = "\0";
}

void Player::setPlayerId(string player)
{
	playerId = player;
}

string Player::getPlayerId()
{
	return playerId;
}

void Player::display()
{
	cout << playerId << endl;
}