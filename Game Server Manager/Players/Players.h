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

void killPlayer(Entity* target);

void kickPlayers(vector<Entity>& entities, Entity*& target);

void banPlayers(vector<Entity>& entities, Entity*& target, vector<Banned>& bannedList);

void viewBannedList(vector<Banned>& bannedList);
