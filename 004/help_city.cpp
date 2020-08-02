#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define endl '\n'

int main()
{
#ifndef ONLINE_JUDGE

    freopen("i1.txt", "r", stdin);
    freopen("o1.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        string inp, oup;
        cin >> inp;
        cin >> oup;

        ll a[n][n];
        memset(a, -1, sizeof(a));
        for (ll j = 0; j < n; j++)
        {
            if (inp[j] == 'N')
            {
                for (ll k = 0; k < n; k++)
                {
                    a[k][j] = 0;
                }
            }
        }

        for (ll j = 0; j < n; j++)
        {
            if (oup[j] == 'N')
            {
                for (ll k = 0; k < n; k++)
                {
                    a[j][k] = 0;
                }
            }
        }

        for (ll j = 0; j < n; j++)
            a[j][j] = 1;

        for (ll j = 1; j < n - 1; j++)
        {
            ll b = j - 1, c = j + 1;
            if (j != 0 && oup[j] == 'Y' && inp[b] == 'Y' && a[j][b] == -1)
                a[j][b] = 1;
            else if (j != 0)
                a[j][b] = 0;
            if (j != n - 1 && oup[j] == 'Y' && inp[c] == 'Y' && a[j][c] == -1)
                a[j][c] = 1;
            else if (j != n - 1)
                a[j][c] = 0;
        }

        if (oup[0] == 'Y' && inp[1] == 'Y' && a[0][1] == -1)
            a[0][1] = 1;
        else
            a[0][1] = 0;
        if (oup[n - 1] == 'Y' && inp[n - 2] == 'Y' && a[n - 1][n - 2] == -1)
            a[n - 1][n - 2] = 1;
        else
            a[n - 1][n - 2] = 0;

        /*cout<<"Case #"<<i+1<<":"<<endl;

		for(ll j=0;j<n;j++)
		{
			for(ll k=0;k<n;k++)
			{
				cout<<a[j][k]<<" ";
			}
			cout<<endl;
		}*/

        for (ll j = 0; j < n; j++)
        {
            for (ll k = j + 2; k < n; k++)
            {
                if (a[j][k] == -1 && a[j][k - 1] == 1 && oup[k - 1] == 'Y' && inp[k] == 'Y')
                    a[j][k] = 1;
                else if (a[j][k] == -1)
                    a[j][k] = 0;
            }
        }

        for (ll j = 0; j < n; j++)
        {
            for (ll k = j - 2; k >= 0; k--)
            {
                if (a[j][k] == -1 && a[j][k + 1] == 1 && oup[k + 1] == 'Y' && inp[k] == 'Y')
                    a[j][k] = 1;
                else if (a[j][k] == -1)
                    a[j][k] = 0;
            }
        }

        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < n; k++)
            {
                if (a[j][k] == 1)
                    cout << 'Y';
                else
                    cout << 'N';
            }
            cout << endl;
        }
    }
}