/*
 * stockInfo.hpp
 *
 *  Created on: Dec 4, 2017
 *      Author: fanwu
 */

#ifndef STOCKINFO_HPP_
#define STOCKINFO_HPP_

#include <string>

using namespace std;

struct StockInfo
{
	StockInfo(double iPrice, string sCompanyName) :
		price(iPrice),
		companyName(sCompanyName) {}

	double price;
	string companyName;
};


#endif /* STOCKINFO_HPP_ */
