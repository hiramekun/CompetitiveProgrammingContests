#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

unordered_map<ll, ll> mp;
ll n;
vector<ll> a;

void solve() {
    ll summ = 0;
    ll d[n + 1];
    rep(i, n + 1) {
        d[i] = abs(a[i + 1] - a[i]);
        summ += d[i];
    }
    repone(i, n) {
        if ((a[i + 1] - a[i]) * (a[i - 1] - a[i]) > 0) {
            cout << summ - 2 * min(d[i], d[i - 1]) << endl;
        } else {
            cout << summ << endl;
        }
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        cin >> n;
        a.resize(n + 2);
        a[0] = 0;
        repone(i, n)cin >> a[i];
        a[n + 1] = 0;

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}