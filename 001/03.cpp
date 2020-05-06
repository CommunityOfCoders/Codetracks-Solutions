// FROG JUMP
// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-1/algorithm/665dbcd94f2d4bce8c5b4d302b21fe57/
// SOLUTION: Sagar

#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
int32_t main() {
    int n;
    cin >> n;
    vector<int> dp(n,0);
    vector<int> step(n,0);
    for(int i = 0; i < n; i++) {
        cin >> step[i];
    }
    dp[1] = abs(step[1]-step[0]);
    for(int i=2;i<n;i++) {
        dp[i] = min((dp[i-1] + abs(step[i]-step[i-1])), (dp[i-2] + abs(step[i]-step[i-2])));
    }
    cout << dp[n-1] << endl;
    return 0;
}