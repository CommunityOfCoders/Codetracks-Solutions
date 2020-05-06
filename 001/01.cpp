// MAKE IT DIVISIBLE
// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-1/algorithm/265336f48fd74977882c27b34fbe06cd/
// SOLUTION: Yash

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << endl;
        } else {
            cout << b - (a % b) << endl;
        }
    }
}