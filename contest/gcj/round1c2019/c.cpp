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

ll r, c;
bool r_invalid[4][4], c_invalid[4][4];

int dfs(bool isB, vector<string> f, int ans) {
    rep(j, r) {
        rep(k, c) {
            if (f[j][k] != '-') {
                if (!r_invalid[j][k]) {
                    rep(l, r) f[l][k] = '-';
                    ans += dfs(!isB, f, ans);
                }
                if (!c_invalid[j][k]) {
                    rep(l, c) f[j][l] = '-';
                    ans += dfs(!isB, f, ans);
                }
            }
        }
    }
    if (!isB) return ans + 1;
    else return ans;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll t = inl();
        rep(i, t) {
            cin >> r >> c;
            vector<string> f;
            rep(j, r) f.eb(ins());

            rep(j, r) rep(k, c) r_invalid[j][k] = c_invalid[j][k] = false;

            rep(j, r) {
                rep(k, c) {
                    if (f[j][k] == '#') {
                        rep(l, r) r_invalid[l][k] = true;
                        rep(l, c) c_invalid[j][l] = true;
                    }
                }
            }
            cout << "Case #" << i + 1 << ": " << dfs(true, f, 0) << endl;

        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}