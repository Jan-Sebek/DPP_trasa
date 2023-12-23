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

// this function takes a reference to an empty map and the name of the source file and fills the map with
// all the stations in the PID system
void loadStops(map<string, Stop>& list, string name); 

// this function takes a map of all the stations and a part of the station's name and prints out
// all stations that contain this parts of the name
void printOptions(map<string, Stop>& s_list, string part);

// this function takes a map of all the stations and the name of the source file and assingns each station
// it's corresponding neighbours
void setupEgdes(map<string, Stop>& list, string name);

// this function takes time as a string and returns number of seconds from midnight
int convertTime(string s_time);

// this function takes a map of all the stations, code of the starting station, code of the destination station
// and an empty path and fills the path with the shortest path from start to destination
void findPath(map<string, Stop>& s_list, string start, string finish, list<Stop>& path);

void zeroStations(map<string, Stop>& s_list);


#endif