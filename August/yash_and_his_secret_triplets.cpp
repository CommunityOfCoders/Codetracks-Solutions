#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll n)
{
    return n * n;
}
int main()
{
    ll a, b, c, d;
    // a is gcd of x and y
    // b is lcm of x and y
    // c is product of x , y and z
    // d is the sum of x , y and z
    cin >> a >> b >> c >> d;
    ll prodxy = a * b;
    ll z = c / prodxy;
    ll sumxy = d - z;
    ll x = (sumxy + sqrt(power(sumxy) - 4 * prodxy)) / 2;
    ll y = d - x - z;
    ll arr[3] = {x, y, z};
    sort(arr, arr + 3);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    return 0;
}