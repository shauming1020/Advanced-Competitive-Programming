# https://leetcode.com/contest/weekly-contest-182/problems/design-underground-system/

#include <iostream>
#include <unordered_map>
#define endl '\n'
using namespace std;
class UndergroundSystem {
public:
	unordered_map<int, pair<string, int>> m;
	unordered_map<string, pair<int, int>> stats;
	UndergroundSystem() {}
	void checkIn(int id, string startStation, int timeIn) {
		m[id] = { startStation, timeIn };
	}
	void checkOut(int id, string endStation, int timeOut) {
		// auto &[startStation, timeIn] = m[id];
		// auto &[totalDuration, tripsCnt] = stats[startStation + ">" + endStation];
		auto &a = m[id];
		auto &startStation = a.first; auto &timeIn = a.second;

		auto &b = stats[startStation + ">" + endStation];
		auto &totalDuration = b.first; auto &tripsCnt = b.second;

		totalDuration += timeOut - timeIn;
		++tripsCnt;
	}
	double getAverageTime(string startStation, string endStation) {
		// auto &[totalDuration, tripsCnt] = stats[startStation + ">" + endStation];
		auto &c = stats[startStation + ">" + endStation];
		auto &totalDuration = c.first; auto &tripsCnt = c.second;
		return (double)totalDuration / tripsCnt;
	}
};
