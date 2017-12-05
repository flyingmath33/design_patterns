/*
 * BaseMaintance.hpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */

#ifndef BASEMAINTANCE_HPP_
#define BASEMAINTANCE_HPP_

#include <vector>

#include "stockInfo.hpp"

class BaseMaintance
{
public:
	virtual void maintain(vector<StockInfo *> &list, int end, int start) = 0;

	virtual void reset(vector<StockInfo *> &list, int &end) = 0;
};



#endif /* BASEMAINTANCE_HPP_ */
