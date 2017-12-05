/*
 * management.hpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */

#ifndef MANAGEMENT_HPP_
#define MANAGEMENT_HPP_

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "stockInfo.hpp"
#include "BaseMaintance.hpp"

using namespace std;

class Management
{
public:
	Management(BaseMaintance *maintance) : lastIndex(-1), pMaintance(maintance){}

	string getPrice(const string &companyName);

	bool update(const string &companyName, double price);

	vector<pair<string, double>> top(const int rank);

	vector<StockInfo *> getList() const { return stockInfoList; }

private:
	vector<StockInfo *> stockInfoList;

	int lastIndex;

	unordered_map<string, StockInfo *> companyToStockInfo;

	BaseMaintance *pMaintance;
};


#endif /* MANAGEMENT_HPP_ */
