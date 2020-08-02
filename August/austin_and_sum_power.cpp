#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[k + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (ll i = 2; i <= k; i++)
        {
            if (i % 2 == 0)
                arr[i] = (n % mod * arr[i / 2] % mod) % mod;
            else
                arr[i] = (n % mod * arr[i / 2] % mod + 1) % mod;
        }
        ll sum = 0;
        for (ll i = 0; i <= k; i++)
            sum = (sum % mod + arr[i] % mod) % mod;
        cout << sum << "\n";
    }
}