#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "functions.h"



using namespace std;

void loadStops(map<string, Stop>& list, string name)
{
	ifstream stops(name);
	string stop;
	bool skip = false;
	int place = 0;
	char prev = 'a';
	string val = "";
	while (stops >> stop)
	{
		skip = false;
		Stop curr_stop;
		if (stop[0] != 'U')
		{
			continue;
		}
		
		for (char c : stop)
		{
			if ((c == 'Z' || c == 'S' || c == 'N') && place == 0)
			{
				skip = true;
			}
			if (place > 3)
			{
				place = 0;
				break;
			}
			if (c == ',')
			{
				if (prev != '"' && place == 1)
				{
					val.push_back(c);
					continue;
				}
				curr_stop.setParam(place, val);
				val.clear();
				place++;
				skip = false;
				continue;
			}
			if (!skip && c != '"')
			{
				val.push_back(c);
			}
			prev = c;
		}
		if (list[curr_stop.getCode()].getCode() == "")
		{
			list[curr_stop.getCode()] = curr_stop;
		}
		else
		{
			list[curr_stop.getCode()].averageCoordinates(curr_stop);
		}
	}
}


void nameSetup(map<string, Stop>& s_list, map<string, string>& n_list)
{
	for (pair<string, Stop> s : s_list)
	{
		n_list[s.second.getName()] = s.first;
	}
}

void printOptions(map<string, Stop>& s_list, string part)
{
	for (pair<string, Stop> s : s_list)
	{
		string name = s.second.getName();
		if (name.find(part) != -1)
		{
			cout << s.first << " " << s.second.getName() << endl;
		}
	}
}


void setupEgdes(map<string, Stop>& list, string name)
{
	ifstream edges(name);

	string edge;
	string val = "";
	string arrival = "";
	string arrival_tmp = "";
	string departure = "";
	string departure_tmp = "";
	string current_stop = "";
	string previous_stop = "";
	string current_line = "";
	int len = 0;
	int len_tmp = 0;

	while (edges >> edge)
	{
		int pos = 1;
		bool skip = false;
		int len = 0;
		for (char c : edge)
		{
			if (c == ',')
			{
				skip = false;
				if (pos == 1)
				{
					if (current_line != val)
					{
						departure = "";
						current_line = val;
					}
				}
				else if (pos == 2)
				{
					arrival_tmp = val;
				}
				else if (pos == 3)
				{
					departure_tmp = val;
					if (departure == "")
					{
						departure = val;
					}
				}
				else if (pos == 4)
				{
					current_stop = val;
				}
				pos++;
				val = "";
				continue;
			}
			if (pos == 4 && c == 'Z')
			{
				skip = true;
			}
			if (!skip)
			{
				val.push_back(c);
			}
		}
		if (current_stop[0] == 'U')
		{
			arrival = arrival_tmp;
			len = convertTime(arrival) - convertTime(departure);
			departure = departure_tmp;
			if (current_stop != previous_stop && len != 0)
			{
				list[current_stop].addNeighbour(previous_stop, len);
			}
			previous_stop = current_stop;
		}
		val = "";
	}


}


int convertTime(string s_time)
{
	int val[3] = { 0,0,0 };
	string temp = "";
	int index = 0;
	for (char c : s_time)
	{
		if (c == ':')
		{
			val[index] = stoi(temp);
			index++;
			temp = "";
			continue;
		}
		temp.push_back(c);

	}
	val[index] = stoi(temp);
	return val[0] * 3600 + val[1] * 60 + val[2];
}

void findPath(map<string, Stop>& s_list, string start, string finish, list<Stop>& path)
{
	priority_queue<Stop, vector<Stop>, greater<Stop>> to_search;
	to_search.push(s_list[start]);
	while (true)
	{
		Stop tmp = to_search.top();
		//std::cout << to_search.size() << std::endl;
		if (tmp.getCode() == finish)
		{
			s_list[start].previous = "";
			cout << "Path found! It takes " << tmp.getPathL() << " seconds to get from " << s_list[start].getName() << " to get to " << s_list[finish].getName() << endl;
			while (tmp.previous != "")
			{
				path.push_front(tmp);
				tmp = s_list[tmp.previous];
			}
			path.push_front(tmp);
			for (pair<string, Stop> stop : s_list)
			{
				s_list[stop.first].visited = false;
			}
			break;
		}
		to_search.pop();
		for (pair<string, int> neigh : tmp.neighbours)
		{
			if (s_list[neigh.first].visited) { continue; }
			s_list[neigh.first].setDistance(s_list[start]);
			s_list[neigh.first].setPathL(tmp.getPathL() + neigh.second);
			s_list[neigh.first].previous = tmp.getCode();
			s_list[neigh.first].visited = true;
			to_search.push(s_list[neigh.first]);
		}

	}

}
