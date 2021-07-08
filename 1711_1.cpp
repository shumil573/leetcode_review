#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	static constexpr int MOD = 1'000'000'007;
	vector<int>& deliciousness = { 1,1,1,3,3,3,7 };

	int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
	int maxSum = maxVal * 2;
	int pairs = 0;
	unordered_map<int, int> mp;
	int n = deliciousness.size();
	for (auto& val : deliciousness) {
		for (int sum = 1; sum <= maxSum; sum <<= 1) {
			int count = mp.count(sum - val) ? mp[sum - val] : 0;
			pairs = (pairs + count) % MOD;
		}
		mp[val]++;
	}
	cout << pairs;
	return 0;
}



