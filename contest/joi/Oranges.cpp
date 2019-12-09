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
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}

ll n, m, k;
ll a[int(1e4)];
ll minb[int(1e4)], maxb[int(1e4)];
ll ans = ll_inf;

void dfs(int ia, int ib, ll sc, ll c, ll minb, ll maxb) {
    if (ia == n) {
        ans = min(ans, sc);
        return;
    }
    minb = min(minb, a[ia]);
    maxb = max(maxb, a[ia]);
    if (c + 1 < m && ia + 1 < n) dfs(ia + 1, ib, sc, c + 1, minb, maxb);
    dfs(ia + 1, ib + 1, sc + k + (c + 1) * (maxb - minb), 0, ll_inf, 0);
}

// x個目以降を詰めるときの最小コスト
ll dfs(ll x) {
    min(dfs(b) + (b - a) * (maxo - mino) + k);
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        cin >> n >> m >> k;
        rep(i, n) a[i] = inl();
        fill(minb, minb + n, ll_inf);
        fill(maxb, maxb + n, 0);
        dfs(0, 0, 0, 0, ll_inf, 0);
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}