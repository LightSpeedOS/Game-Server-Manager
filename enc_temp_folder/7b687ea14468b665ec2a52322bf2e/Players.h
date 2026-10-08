#pragma once

#include "Headers/Struct.h"
#include "Headers/Includes.h"

void createPlayers(vector<Entity>& entities);

void listPlayers(const vector<Entity>& entities);

void addPlayer(vector<string>& names, vector<Entity>& entities);

Entity* findTarget(vector<Entity>& entities);

void viewTarget(Entity* target);

void changeName(Entity* target);

void hurtPlayer(Entity* target);
