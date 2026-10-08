#include "Players.h"
#include "Headers/Logic.h"

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
	cout << target->health << " Health : " << healthSnapshot << " -> " << target->health << endl;
	getKey();
}