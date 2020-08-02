#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
ll change(ll n){
if(n%2)return n*2;
else return n/2;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        ll dp[n][2];
        dp[0][0]=dp[0][1]=0;
        for(ll i=1;i<n;i++){
            dp[i][0]=min(dp[i-1][1]+abs(change(a[i-1])-a[i]),dp[i-1][0]+abs(a[i-1]-a[i]));
            dp[i][1]=min(dp[i-1][1]+abs(change(a[i-1])-change(a[i])),dp[i-1][0]+abs(a[i-1]-change(a[i])));
        }
        cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    }
    return 0;
}
