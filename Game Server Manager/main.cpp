#include "Headers/Includes.h"
#include "Headers/Struct.h"
#include "Headers/Logic.h"
#include "Players/Players.h"
#include "Names/Names.h"


auto main() -> int
{
	initConsole();

	vector<Entity> entities;
	createPlayers(entities);

	Entity* currentTarget = nullptr;

	string fileName = R"(C:\Users\Jamaal\source\repos\LightSpeedOS\Game-Server-Manager\Game Server Manager\Names\names.txt)";
	vector<string> names = loadNames(fileName);

	int mainOption;

	while (true)
	{
		clear();

		printInfo(currentTarget);

		cout << "[1] List Player" << endl;
		cout << "[2] Add Player" << endl;
		cout << "[3] Select Player" << endl;
		cout << "[4] View Selected Player" << endl;
		cout << "[5] Change Username" << endl;
		cout << "[6] Admin Panel" << endl;
		cout << "[7] Exit" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		if (input())
		{
			continue;
		}

		switch (mainOption)
		{
		case ListPlayers:
			listPlayers(entities);
			break;

		case AddPlayer:
			addPlayer(names, entities);
			break;

		case SelectPlayer:
			currentTarget = findTarget(entities);
			break;

		case ViewSelected:
			viewTarget(currentTarget);
			break;

		case ChangeUser:
			changeName(currentTarget);
			break;

		case AdminMenu:
			adminPanel(currentTarget, entities);
			break;

		case Exit:
			shutDown();
			break;
			
		default:
			invalid();
			break;
		}
	}
}