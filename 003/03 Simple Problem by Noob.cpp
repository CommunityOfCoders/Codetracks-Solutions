// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-3/algorithm/9bd823e39610469284e2b8dcac9fd900/
// SOLUTION: Yash

// The test cases for this problem were very weak
// Intended solution is O(m + n)
// we generate pattern using diff array of smaller hist
// we generate text using diff array of larger hist
// and ans is count of occurrences of pattern in text

#include <bits/stdc++.h>
using namespace std;

vector<int> kmp_prefix(vector<int> s) {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if (m == 1) {
        cout << n << endl;
    } else {
        vector<int> d(n + m - 1);
        for (int i = 1; i < m; i++) {
            d[i - 1] = b[i] - b[i - 1];
        }
        d[m - 1] = INT_MAX;
        for (int i = 1; i < n; i++) {
            d[m + i - 1] = a[i] - a[i - 1];
        }
        d = kmp_prefix(d);
        int count = 0;
        for (auto x : d) {
            if (x == m - 1) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
