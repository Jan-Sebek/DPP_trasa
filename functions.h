#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include "Stop.h"

using namespace std;

void loadStops(map<string, Stop>& list, string name);

void nameSetup(map<string, Stop>& s_list, map<string, string>& n_list);

void printOptions(map<string, Stop>& s_list, string part);

void setupEgdes(map<string, Stop>& list, string name);

int convertTime(string s_time);

void findPath(map<string, Stop>& s_list, string start, string finish, list<Stop>& path);


#endif