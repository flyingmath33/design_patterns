//============================================================================
// Name        : stockManagement.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <utility>
#include "stockInfo.hpp"
#include "HeapMaintance.hpp"
#include "management.hpp"

using namespace std;

int main() {
	BaseMaintance *pMaintance = new HeapMaintance();
	Management manual(pMaintance);

	manual.update("IBM", 120.0);
	manual.update("GOOG", 220.0);
	manual.update("AAPL", 137.0);
	manual.update("T", 59.0);
	cout << manual.getPrice("IBM") << endl;
	cout << manual.getPrice("Goog") << endl;

	vector<StockInfo *> list = manual.getList();
	for(int i = 0; i < (int)list.size(); ++i)
		cout << list[i]->price << ", " << list[i]->companyName << endl;

	cout << endl;

	manual.update("GOOG", 20.0);
	list = manual.getList();
	for(int i = 0; i < (int)list.size(); ++i)
		cout << list[i]->price << ", " << list[i]->companyName << endl;

	cout << "top ticks: " << endl;
	vector<pair<string, double>> res1 = manual.top(1);
	for(int i = 0; i < (int)res1.size(); ++i)
			cout << res1[i].first << ", " << res1[i].second << endl;

	return 1;
}
