// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-3/algorithm/cf6d580b278c48848f805cb48e88e8ef/
// SOLUTION: Yash

// solution is based on bitmask dp technique
// intended complexity O(T * 2^n * 3)

#include <bits/stdc++.h>
using namespace std;

#define HELL (int) (1e9 + 7)

int n, t;
const int maxN = 20, maxT = 250;
pair<int, int> arr[maxN];
int dp[maxT][1 << 16][4];
 
int ways(int time, int mask, int prev) {
	if (time > t) return 0;
	if (time == t) return 1;
	int &ans = dp[time][mask][prev];
	if (ans == -1) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) == 0) {
				if (arr[i].second != prev) {
					ans = (ans + ways(time + arr[i].first, mask | (1 << i), arr[i].second)) % HELL;
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	memset(dp, -1, sizeof dp);
	cout << ways(0, 0, 0) << endl;
	return 0;
}