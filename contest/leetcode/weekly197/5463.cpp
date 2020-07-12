#ifdef MY_DEBUG
#include <bits/stdc++.h>
using namespace std;
#endif

using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<double, double>;
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
class Solution {
public:
    double dis(P a, P b) { return sqrt(pow(a.F - b.F, 2) + pow(a.S - b.S, 2)); }
    double dis(P a, vector<vector<int>> &pos) {
        double ret = 0;
        each(e, pos) { ret += sqrt(pow(a.F - e[0], 2) + pow(a.S - e[1], 2)); }
        return ret;
    }

    double getMinDistSum(vector<vector<int>> &positions) {
        P xy{0, 0};
        double d = dis(xy, positions);
        double step = 100.0;

        int done = 0;

        while (step > 0.000001) {
            done = 0;
            for (int i = 0; i < 4; ++i) {
                double nx = (double)xy.first + step * dx[i];
                double ny = (double)xy.second + step * dy[i];

                double t = dis(P(nx, ny), positions);

                if (t < d) {
                    d = t;
                    xy = P(nx, ny);
                    done = 1;
                    break;
                }
            }

            if (!done) step /= 2;
        }
        return d;
    }
};