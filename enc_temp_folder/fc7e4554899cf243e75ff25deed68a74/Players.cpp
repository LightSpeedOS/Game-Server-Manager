#include "Players.h"
#include "Headers/Logic.h"
#include "Headers/Struct.h"

void createPlayers(vector<Entity>& entities)
{
	Entity james("James", returnHealth(), returnPos(), returnPos());
	entities.push_back(james);

	Entity grace("Grace", returnHealth(), returnPos(), returnPos());
	entities.push_back(grace);

	Entity ethen("Ethan", returnHealth(), returnPos(), returnPos());
	entities.push_back(ethen);

	Entity marcus("Marcus", returnHealth(), returnPos(), returnPos());
	entities.push_back(marcus);

	Entity chloe("Chloe", returnHealth(), returnPos(), returnPos());
	entities.push_back(chloe);
}

void listPlayers(const vector<Entity>& entities)
{
	clear();

	cout << "========= PLAYER LIST =========" << endl;
	space();

	cout << left << setw(16) << "NAME" << setw(10) << "HEALTH" << "POS" << endl;
	cout << "-----------------------------------" << endl;

	for (const Entity& e : entities)
	{
		cout << left << setw(16) << e.name << healthColor(&e) << "  " << setw(8) << e.health << reset << " (" << e.positions.x << ", " << e.positions.y << ")" << endl;
	}

	getKey();
}

void addPlayer(vector<string>& names, vector<Entity>& entities)
{
	clear();

	if (names.empty())
	{
		cout << "[!] You Have Hit The Limit" << endl;
		pause();
		return;
	}

	int index = drawName(names);
	string name = names[index];
	names.erase(names.begin() + index);

	Entity newPlayer(name, returnHealth(), returnPos(), returnPos());
	entities.push_back(newPlayer);

	cout << "[+] " << green << "Successfully " << reset << "Added a New Player, Name: " << name << endl;
	getKey();
}

Entity* findTarget(vector<Entity>& entities)
{
	clear();

	int index = rand() % entities.size();

	cout << "[+] " << green << "Successfully " << reset << "Selected -> " << entities[index].name << endl;
	getKey();

	return &entities[index];
}

void viewTarget(Entity* target)
{
	clear();

	if (!isValid(target))
	{
		cout << "[!] No Target Selected" << endl;
		pause();
		return;
	}

	cout << "========= Current Target =========" << endl;
	space();

	cout << left << setw(16) << "NAME" << setw(10) << "HEALTH" << "POS" << endl;
	cout << "-----------------------------------" << endl;

	cout << left << setw(16) << target->name << healthColor(target) << setw(8) << target->health << reset << " (" << target->positions.x << ", " << target->positions.y << ")" << endl;

	getKey();
}

void changeName(Entity* target)
{
	clear();

	if (!isValid(target))
	{
		cout << "[!] No Target Selected" << endl;
		pause();
		return;
	}

	string newName;
	const string nameSnapshot = target->name;

	cout << "Enter New Name: ";
	cin.ignore();
	getline(cin, newName);

	if (newName.empty())
	{
		space();
		cout << "[!] Name Cannot Be Left Empty" << endl;
		pause();
		return;
	}

	target->name = newName;
	cout << "[+] " << green << "Successfully " << reset << "Changed Name From " << nameSnapshot << " -> " << target->name << "!" << endl;
	getKey();
}

void hurtPlayer(Entity* target)
{
	clear();

	if (!isValid(target))
	{
		cout << "[!] No Target Selected" << endl;
		pause();
		return;
	}

	const int dmg = damage();
	const int healthSnapshot = target->health;
	target->health -= dmg;

	cout << "[+] " << target->name << " Took " << dmg << " Damage" << endl;
	cout << target->name << " Health : " << healthSnapshot << " -> " << target->health << endl;
	getKey();
}

void killPlayer(Entity* target)
{
	clear();

	if (!isValid(target))
	{
		cout << "[!] No Target Selected" << endl;
		pause();
		return;
	}

	const int healthSnapshot = target->health;
	target->health = 0;

	cout << "[+] You Killed " << target->name << " Health: " << healthSnapshot << " -> " << target->health << endl;
	getKey();
}

void kickPlayers(vector<Entity>& entities, Entity*& target)
{
	while (true)
	{
		clear();

		if (entities.empty())
		{
			cout << "[-] No players to kick!" << endl;
			getKey();
			return;
		}

		cout << "========= Player List =========" << endl;
		space();

		cout << left << setw(4) << "#" << setw(16) << "NAME" << setw(10) << "HEALTH" << "POS" << endl;
		cout << "---------------------------------------" << endl;

		for (size_t i = 0; i < entities.size(); i++)
		{
			cout << left << setw(4) << i + 1
				<< setw(16) << entities[i].name
				<< healthColor(&entities[i]) << "  " << setw(8) << entities[i].health << reset
				<< "(" << entities[i].positions.x << ", " << entities[i].positions.y << ")" << endl;
		}

		space();
		int index;
		cout << "Select an Index: ";
		cin >> index;

		if (input())
		{
			continue;
		}

		if (index > (int)entities.size() || index < 1)
		{
			invalid();
			continue;
		}

		clear();
		index--;

		const string kickedName = entities[index].name;
		entities.erase(entities.begin() + index);
		target = nullptr;

		cout << "[+] " << green << "Successfully " << reset << "Kicked " << kickedName << "!" << endl;

		getKey();
		break;
	}
}

void banPlayers(vector<Entity>& entities, Entity*& target, vector<Banned>& bannedList)
{
	while (true)
	{
		clear();

		if (entities.empty())
		{
			cout << "[-] No players to Ban!" << endl;
			getKey();
			return;
		}

		cout << "========= Player List =========" << endl;
		space();

		cout << left << setw(4) << "#" << setw(16) << "NAME" << setw(10) << "HEALTH" << "POS" << endl;
		cout << "---------------------------------------" << endl;

		for (size_t i = 0; i < entities.size(); i++)
		{
			cout << left << setw(4) << i + 1
				<< setw(16) << entities[i].name
				<< healthColor(&entities[i]) << "  " << setw(8) << entities[i].health << reset
				<< "(" << entities[i].positions.x << ", " << entities[i].positions.y << ")" << endl;
		}

		space();
		int index;
		cout << "Select an Index: ";
		cin >> index;

		if (input())
		{
			continue;
		}

		if (index > (int)entities.size() || index < 1)
		{
			invalid();
			continue;
		}

		clear();
		index--;
		const string bannedName = entities[index].name;
		
		cout << "Selected Player: " << entities[index].name << endl;
		space();
		
		cout << "[1] Temporary Ban   [2] Permanent Ban   [R] Return" << endl;

		char key = _getch();

		switch (tolower(key))
		{
		case '1':
		{
			Banned temp(bannedName, "Exploit", BanType::Temporary, 30);
			bannedList.push_back(temp);

			cout << "[+] " << green << "Successfully " << reset << "Temp Ban " << bannedName << "!" << endl;
			getKey();
			break;
		}

		case '2':
		{
			Banned perm(bannedName, "Cheating", BanType::Permanent, 999);
			bannedList.push_back(perm);
			cout << "[+] " << green << "Successfully " << reset << "Struck " << bannedName << " With The Ban Hammer!" << endl;
			getKey();
			break;
		}

		case 'r':

			return;

		default:
			invalid();
			while (_kbhit()) _getch();
			break;
		}

		entities.erase(entities.begin() + index);
		target = nullptr;
		break;
	}
}

void viewBannedList(vector<Banned>& bannedList)
{
	clear();

	if (bannedList.empty())
	{
		cout << "[!] Banned List is Empty" << endl;
		pause();
		return;
	}

	cout << "========= Banned List =========" << endl;
	space();

	cout << left << setw(16) << "NAME" << setw(12) << "STATUS" << setw(16) << "REASON" << "LENGTH" << endl;
	cout << "--------------------------------------------------" << endl;

	for (const Banned& b : bannedList)
	{
		cout << left << setw(16) << b.name << setw(12) << banTypeText(b.bantype) << setw(16) << b.reason << b.legnth << " days" << endl;
	}

	getKey();

}