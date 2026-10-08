#include "Names.h"

vector<string> loadNames(const string& fileName)
{
	vector<string> names;

	ifstream file(fileName);


	if (!file.is_open())
	{
		clear();
		cout << "[!] Could Not Open File" << endl;
		getKey();
		return names;
	}

	string name;

	while (file >> name)
	{
		names.push_back(name);
	}

	return names;
}