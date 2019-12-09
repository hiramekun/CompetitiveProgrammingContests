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

const int MAX_V = half_inf;
vector<int> G[half_inf];
vl d(half_inf);

ll dfs(ll s) {
    ll res = 0;
    if (d[s] != -1) return d[s];

    rep(i, G[s].size()) {
        res = max(res, dfs(G[s][i]) + 1);
    }
    d[s] = res;
    return res;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif

        int V, E;
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; ++i) {
            int s, t;
            scanf("%d %d", &s, &t);
            s--, t--;
            G[s].eb(t);
        }
        rep(i, V) d[i] = -1;

        ll ans = 0;
        rep(i, V) ans = max(ans, dfs(i));
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}