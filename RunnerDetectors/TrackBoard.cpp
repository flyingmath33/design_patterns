/*
 * TackBoard.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: fanwu
 */

#include "TrackBoard.h"

using namespace std;

TrackBoard::TrackBoard(int sensors, int runners)
{
	numOfSensors = sensors;
	numOfRunners = runners;

	mSensors = vector<unordered_set<int>>(sensors, unordered_set<int>());
	for(int i = 0; i < numOfRunners; ++i)
		mRunners[i] = -1;
}

void TrackBoard::move(int runner)
{
	if(runner >= numOfRunners || mRunners[runner] == int(mSensors.size()) - 1)
		return;

	++mRunners[runner];
	if(mRunners[runner] > 0)
		mSensors[mRunners[runner] - 1].erase(runner);

	mSensors[mRunners[runner]].insert(runner);
}

void TrackBoard::display()
{
	for(int i = numOfSensors - 1; i >= 0; --i)
	{
		for(auto a : mSensors[i])
			cout << a << ": Rank " << i << endl;
	}
}


