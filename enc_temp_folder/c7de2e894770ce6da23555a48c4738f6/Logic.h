#pragma once
#include "Players/Players.h"

inline void printInfo(Entity* target)
{
	cout << "====== GAME SERVER MANAGER ======" << endl;
	space();

	if (target == nullptr)
	{
		cout << "Current Selected Player: None" << endl;
	}
	
	else
	{
		cout << "Current Selected Player: " << target->name << endl;
	}
	space();
}

inline void printAdmin(Entity* target)
{
	clear();

	cout << "====== Admin Panel ======" << endl;
	space();

	if (target == nullptr)
	{
		cout << "Current Selected Player: None" << endl;
	}

	else
	{
		cout << "Current Selected Player: " << target->name << endl;
	}
	space();
}

inline bool isValid(const Entity* e)
{
	if (e != nullptr) return true;
	return false;
}

inline const char* healthColor(const Entity* e)
{
	if (e->health > 50) return green;
	if (e->health > 20) return yellow;
	else return red;

	return reset;
}

inline int returnHealth()
{
	return rand() % 100 + 1;
}


inline int returnPos()
{
	return rand() % 1000 + 1;
}

inline int drawName(vector<string>& names)
{
	return rand() % names.size();
}

inline int damage()
{
	return rand() % 60 + 1;
}

inline void adminPanel(Entity* target, vector<Entity>& entities)
{
	printAdmin(target);

	int adminOption;

	while (true)
	{
		clear();

		cout << "[1] Hurt Player" << endl;
		cout << "[2] Kill Player" << endl;
		cout << "[3] Kick Player" << endl;
		cout << "[4] Ban Player" << endl;
		cout << "[5] View Banned Player" << endl;
		cout << "[6] Return" << endl;

		space();
		cout << "> ";
		cin >> adminOption;

		if (input())
		{
			continue;
		}

		switch (adminOption)
		{

		case HurtPlayer:
			hurtPlayer(target);
			break;

		case KillPlayer:

			break;

		case KickPlayer:

			break;

		case BanPlayer:

			break;

		case ViewBanned:

			break;

		case Return:

			return;

		default:
			invalid();
			break;
		}
	}
}