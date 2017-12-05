/*
 * management.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "management.hpp"

using namespace std;

string Management::getPrice(const string &companyName)
{
	if(companyToStockInfo.find(companyName) == companyToStockInfo.end())
		return "ERROR:companyDoesNotExist";

	return to_string(companyToStockInfo[companyName]->price);
}

bool Management::update(const string &companyName, double price)
{
	if(companyToStockInfo.find(companyName) == companyToStockInfo.end())
	{
		companyToStockInfo[companyName] = new StockInfo(price, companyName);
		stockInfoList.push_back(companyToStockInfo[companyName]);
	}

	companyToStockInfo[companyName]->price = price;
	pMaintance->reset(stockInfoList, lastIndex);

	return true;
}

vector<pair<string, double>> Management::top(const int rank)
{
	int size = min((int)rank, (int)stockInfoList.size());

	if(rank > stockInfoList.size() - 1 - lastIndex)
	{
		pMaintance->reset(stockInfoList, lastIndex);
		for(int i = 1; i <= size; ++i)
		{
			swap(stockInfoList[0], stockInfoList[stockInfoList.size() - i]);
			--lastIndex;
			pMaintance->maintain(stockInfoList, lastIndex, 0);
		}
	}

	vector<pair<string, double>> res(size, make_pair("", 0.0));
	for(int i = 1; i <= size; ++i)
		res[i - 1] = make_pair(
				stockInfoList[stockInfoList.size() - i]->companyName,
				stockInfoList[stockInfoList.size() - i]->price);

	return res;
}


