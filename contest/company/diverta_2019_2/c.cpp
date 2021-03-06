#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using V = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

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

/* ----------- ANSWER ----------- */
/* ------------------------------ */

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl();
        vl a(n);
        rep(i, n) cin >> a[i];

        sort(all(a));
        V<P> ans;
        ll bg = a.back(), sml = a[0];
        for (long long i = 1; i < n - 1; ++i) {
            if (a[i] <= 0) {
                ans.eb(P(bg, a[i]));
                bg -= a[i];
            } else {
                ans.eb(P(sml, a[i]));
                sml -= a[i];
            }
        }
        ans.eb(P(bg, sml));
        cout << bg - sml << endl;
        each(m, ans) cout << m.F << " " << m.S << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
