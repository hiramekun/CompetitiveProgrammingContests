#include <cstring>
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
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = i_half_inf;
ll N;
ll a[MAX_N], b[MAX_N];

void solve() {
    ll ans = 0, added = 0;
    repr(i, N) {
        a[i] += added;
        if (a[i] % b[i] != 0) {
            ll temp = (b[i] - a[i] % b[i]);
            ans += temp;
            added += temp;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    rep(i, N) cin >> a[i] >> b[i];
    solve();
    return 0;
}
