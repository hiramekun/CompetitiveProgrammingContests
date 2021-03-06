#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef pair<ll, ll> P;
typedef vector<ll> vll;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll x = inl(), y = inl(), z = inl(), k = inl();
        vll a(x), b(y), c(z);
        rep(i, x) a[i] = inl();
        rep(i, y) b[i] = inl();
        rep(i, z) c[i] = inl();

        vll ab;
        rep(i, x) rep(j, y) ab.eb(a[i] + b[j]);
        sort(all(ab), greater<>());
        sort(all(c), greater<>());

        vll ans(k);
        rep(i, min(x * y, k)) rep(j, min(z, k)) ans.eb(ab[i] + c[j]);
        sort(all(ans), greater<>());
        rep(i, k) cout << ans[i] << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}