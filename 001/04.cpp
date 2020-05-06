// SPREAD IT
// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-1/algorithm/a06a8671100849b4a50aec4f5402f61b/
// SOLUTION: Yash
// Solution is based on Tree DP 

#include <bits/stdc++.h>
using namespace std;
 
int n, r;
const int maxN = 1e5 + 5;
vector<int> adj[maxN];
 
int dfs(int node, int parent) {
    int res = 0;
    vector<int> children;

    // for all the children of current node get the ans and store it in children array
    for (auto x : adj[node]) {
        if (x != parent) {
            children.push_back(dfs(x, node));
        }
    }

    // sort the answers in non increasing order
    sort(children.begin(), children.end(), greater<int>());
    
    // We greedily pass on the signal to the node with the highest answer
    // so for first child we add 1, for second we add 2, and so on
    // finally we take max over this operation and that is the answer for the current node
    for (int i = 0; i < children.size(); i++) {
        res = max(res, i + 1 + children[i]);
    }
    return res;
}
 
int main() {
    cin >> n >> r;
    int u, v;

    // input the tree in adj list
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs() returns the answer for the subtree of the node passed in
    // we print dfs(r, -1) as r is root and it has no parent
    cout << dfs(r, -1) << endl;
    return 0;
}