#pragma once

#ifndef STOP_H
#define STOP_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class Stop
{
public:
	Stop();
	~Stop();
	void setParam(int param, string val);
	void setParam(int param, float val);
	void printStop();
	string getCode();
	string getCoordinates();
	void addNeighbour(string prev, int len);
	string getNeighbours();
	string getNeighbours(map<string, Stop>& list);
	void averageCoordinates(Stop new_s);
	float getLatitude();
	float getLongtitude();
	string getName();
	void setDistance(Stop s);
	double getDistance(Stop s);
	void setPathL(double l);
	int getPathL();

	map<string, int> neighbours;

	double h;
	bool visited;
	string previous; 

	bool operator>  (Stop const& v) const { return h > v.h; };

private:
	string m_code;
	string m_name;
	float m_lat;
	float m_long;
	int m_sameStop;
	double m_distance;
	double m_path_len;

};

#endif
