/*
 * HeapMaintance.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */
#include <vector>

#include "stockInfo.hpp"
#include "HeapMaintance.hpp"

using namespace std;

void HeapMaintance::maintain(vector<StockInfo *> &list, int end, int start)
{
	// This is the Heapify function.
	for(++start, ++end; start <= end;)
	{
		int next = start;

		int left = 2 * start > end ? -1 : 2 * start;
		int right = 2 * start + 1 ? -1 : 2 * start + 1;

		if(left >= 0 && list[start - 1]->price < list[left - 1]->price)
			next = left;

		if(right >= 0 && list[next - 1]->price < list[right - 1]->price)
			next = right;

		if(next == start)
			return;

		swap(list[start - 1], list[next - 1]);

		start = next;
	}
}

void HeapMaintance::reset(vector<StockInfo *> &list, int &lastIndex)
{
	if(list.empty())
	{
		lastIndex = -1;
		return;
	}

	lastIndex = list.size() - 1;
	for(int i = list.size() / 2; i >= 0; --i)
		maintain(list, lastIndex, i);
}


