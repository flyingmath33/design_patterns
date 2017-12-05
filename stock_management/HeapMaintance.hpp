/*
 * HeapMaintance.hpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */

#ifndef HEAPMAINTANCE_HPP_
#define HEAPMAINTANCE_HPP_

#include "BaseMaintance.hpp"

using namespace std;

class HeapMaintance: public BaseMaintance
{
public:
	void maintain(vector<StockInfo *> &list, int end, int start);

	void reset(vector<StockInfo *> &list, int &end);
};

#endif /* HEAPMAINTANCE_HPP_ */
