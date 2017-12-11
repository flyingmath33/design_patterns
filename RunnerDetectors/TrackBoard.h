/*
 * TrackBoard.h
 *
 *  Created on: Dec 10, 2017
 *      Author: fanwu
 */

#ifndef TRACKBOARD_H_
#define TRACKBOARD_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

class TrackBoard
{
public:
	TrackBoard(int sensors, int runners);

	void move(int runner);
	void display();
private:
	int numOfSensors;
	int numOfRunners;
	vector<unordered_set<int>> mSensors;
	unordered_map<int, int> mRunners;
};


#endif /* TRACKBOARD_H_ */
