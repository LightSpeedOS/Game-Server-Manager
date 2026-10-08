#pragma once

#include "Includes.h"

enum mainMenu
{
	ListPlayers = 1,
	AddPlayer,
	SelectPlayer,
	ViewSelected,
	ChangeUser,
	AdminMenu,
	Exit
};

enum adminMenu
{
	HurtPlayer = 1,
	KillPlayer,
	KickPlayer,
	BanPlayer,
	ViewBanned,
	Return,
};

struct Vec2
{
	float x, y;
};

struct Entity
{
	string name;
	int health;

	Vec2 positions;

	Entity(string newName, int newHealth, float posX, float posY)
	{
		name = newName;
		health = newHealth;
		positions.x = posX;
		positions.y = posY;
	}
};