#include "bits/stdc++.h"
#define int long long
#define float double
#define double long double
#define endl "\n"
#define debug cout << "Good uptill here" << endl \
                   << flush;
#define deb(x) cout << #x << ":" << x << endl \
                    << flush;

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int cnt[n][26] = {0};

    cnt[0][s[0] - 'a']++;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a']++;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int cur[26] = {0};
        for (int i = 0; i < 26; i++)
            cur[i] = cnt[r][i];

        if (l > 0)
        {
            for (int i = 0; i < 26; i++)
                cur[i] -= cnt[l - 1][i];
        }

        char c;
        int maxi = 0;
        for (int i = 0; i < 26; i++)
        {
            if (maxi <= cur[i])
            {
                maxi = cur[i];
                c = 'a' + i;
            }
        }
        cout << c << " " << maxi << endl;
    }
    return 0;
}