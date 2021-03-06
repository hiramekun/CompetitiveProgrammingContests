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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll N, M, Q;
vector<ll> l, r, p, q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    scanf("%lli%lli%lli", &N, &M, &Q);
    l.resize(M), r.resize(M), p.resize(Q), q.resize(Q);
    ll d[N + 1][N + 1];
    fill(d[0], d[N + 1], 0);
    rep(i, M) {
        scanf("%lli%lli", &l[i], &r[i]);
        d[l[i]][r[i]]++;
    }
    ll dp[N + 1][N + 1];
    fill(dp[0], dp[N + 1], 0);

    repone(i, N)repone(j, N) dp[i][j] = dp[i][j - 1] + d[i][j];

    rep(i, Q) {
        scanf("%lli%lli", &p[i], &q[i]);
        ll ans = 0;
        for (ll j = p[i]; j <= q[i]; ++j) {
            ans += dp[j][q[i]] - dp[j][p[i] - 1];
        }
        printf("%lli\n", ans);
    }
    return 0;
}
