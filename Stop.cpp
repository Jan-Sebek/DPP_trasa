#include "Stop.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>



using namespace std;


Stop::Stop()
{
	m_code = "";
	m_name = "";
	m_sameStop = 0;
	m_lat = 0.0;
	m_long = 0.0;
	m_path_len = 0;
	m_distance = 0;
	h = 0.0;
	visited = false;
	string previous = "";
}

Stop::~Stop()
{
}


void Stop::setParam(int param, string vall)
{
	if (param == 0)
	{
		m_code = vall;
	}
	else if (param == 1)
	{
		m_name = vall;
	}
	else if (param == 2)
	{
		m_lat = stof(vall);
	}
	else if (param == 3)
	{
		m_long = stof(vall);
	}
}

void Stop::setParam(int param, float vall)
{
	if (param == 2)
	{
		m_lat = vall;
	}
	else if (param == 3)
	{
		m_long = vall;
	}
}

void Stop::printStop()
{
	cout << m_name << endl;
}

string Stop::getCode()
{
	return m_code;
}

string Stop::getCoordinates()
{
	return to_string(m_lat) + "N " + to_string(m_long) + "E";
}

void Stop::addNeighbour(string prev, int len)
{
	if (neighbours[prev] > len || neighbours[prev] == 0)
	{
		neighbours[prev] = len;
	}
}

string Stop::getNeighbours()
{
	string out = "";
	if (neighbours.size() == 0)
	{
		return out;
	}
	for (pair<string, int> neigh : neighbours)
	{
		out += neigh.first + " " + to_string(neigh.second) + "secs; ";
	}
	return out;
};

string Stop::getNeighbours(map<string, Stop>& list)
{
	string out = "";
	if (neighbours.size() == 0)
	{
		return out;
	}
	for (pair<string, int> neigh : neighbours)
	{
		out += list[neigh.first].getName() + " " + to_string(neigh.second) + "secs; ";
	}
	return out;
};

float Stop::getLatitude()
{
	return m_lat;
}

float Stop::getLongtitude()
{
	return m_long;
}

void Stop::averageCoordinates(Stop new_s)
{
	m_lat = m_lat * m_sameStop + new_s.getLatitude();
	m_long = m_long * m_sameStop + new_s.getLongtitude();
	m_sameStop++;
	m_lat = m_lat / m_sameStop;
	m_long = m_long / m_sameStop;
}

string Stop::getName()
{
	return m_name;
}

void Stop::setDistance(Stop s)
{
	m_distance = sqrt((m_lat - s.getLatitude())*(m_lat - s.getLatitude()) + (m_long - s.getLongtitude())* (m_long - s.getLongtitude()));
	h = m_distance + m_path_len;
}

double Stop::getDistance()
{
	return m_distance;
}

void Stop::setPathL(double l)
{
	m_path_len = l;
	h = m_distance + m_path_len;
}

int Stop::getPathL()
{
	return m_path_len;
}