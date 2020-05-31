#ifdef MY_DEBUG
#include <bits/stdc++.h>
using namespace std;
#endif

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for (auto &i : mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template <class T> ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template <class T> istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template <class T> ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
// nCr: v[n][r]
vector<vector<ll>> comb(ll n, ll r) {
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}
class Solution {
public:
    double getProbability(vector<int> &balls) {
        ll n = balls.size();
        double chil = 0;
        ll k = accumulate(all(balls), 0LL);
        vvl table = comb(k, k / 2);
        ll moth = table[k][k / 2];
        vl a(n), b(n);
        auto rec = [&](auto &&f, ll i, vl &A, vl &B, ll multi) -> void {
            if (i == n) {
                if (accumulate(all(A), 0LL) == accumulate(all(B), 0LL)) {
                    ll acnt = 0, bcnt = 0;
                    rep(j, n) {
                        if (A[j] > 0) acnt++;
                        if (B[j] > 0) bcnt++;
                    }
                    if (acnt == bcnt) chil += multi;
                }
                return;
            }
            ll ballcnt = balls[i];
            for (ll j = 0; j <= ballcnt; ++j) {
                A[i] = j;
                B[i] = ballcnt - j;
                f(f, i + 1, A, B, multi * table[ballcnt][j]);
                A[i] = 0;
                B[i] = 0;
            }
        };
        rec(rec, 0, a, b, 1);
        return chil / moth;
    }
};