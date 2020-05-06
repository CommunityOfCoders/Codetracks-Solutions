// MOMO's MARKET
// PROBLEM: https://www.hackerearth.com/challenges/college/codetracks-1/algorithm/d7d7e404fd2849ac9c15476efb897dc2/
// SOLUTION: Sagar

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    long long int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = 1; i < n; i++)
        arr[i] += arr[i-1];
    
    int q;
    cin >> q;
    while (q--) {
        long long int X;
        cin >> X;
        
    int shops = upper_bound(arr,arr+n,X)-arr;
    if(shops == 0)
        cout<< shops << " " << X << endl;
    else
        cout<< shops << " " << X-arr[shops-1] << endl;
    }
	return 0;
}