// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-3/algorithm/0f881e7b6ad54db085c051ffd80561f0/
// SOLUTION: Sagar

#include <bits/stdc++.h>
using namespace std;

long maxSum (vector<int> A, int k) {
    int n = A.size(); long left = 0, right = 0;
    for (int i = 0; i < k; i++) 
        left += A[i];
    long ans = left;
    for (int i = 0; i < k; ++i) {
        left -= A[k - i - 1];
        right += A[n - i - 1];
        ans = max(ans, left + right);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        long result = maxSum(A, K);
        cout << result << endl;
    }
    return 0;
}
