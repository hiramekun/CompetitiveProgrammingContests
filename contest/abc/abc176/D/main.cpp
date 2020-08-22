#include <bits/stdc++.h>

using namespace std;

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
#define F firstdd
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

void solve() {
    ll h, w;
    cin >> h >> w;
    ll startx, starty, endx, endy;
    cin >> startx >> starty >> endx >> endy;
    startx--, starty--, endx--, endy--;

    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    vector<vector<ll>> cnts(h, vector<ll>(w, ll_inf));  // 魔法使った回数
    queue<P> q, nq;
    q.push(P(startx, starty));
    cnts[startx][starty] = 0;

    while (!q.empty() || !nq.empty()) {
        if (!q.empty()) {
            ll nowx = q.front().first, nowy = q.front().second;
            nq.push(P(nowx, nowy));
            q.pop();
            rep(i, 4) {
                ll nx = nowx + dx[i], ny = nowy + dy[i];
                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1) {
                    if (s[nx][ny] == '#') continue;
                    if (cnts[nowx][nowy] < cnts[nx][ny]) {
                        cnts[nx][ny] = cnts[nowx][nowy];
                        q.push(P(nx, ny));
                    }
                }
            }

        } else {
            ll nowx = nq.front().first, nowy = nq.front().second;
            nq.pop();
            for (ll i = -2; i <= 2; ++i) {
                for (ll j = -2; j <= 2; ++j) {
                    ll nx = nowx + i, ny = nowy + j;
                    if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1) {
                        if (s[nx][ny] == '#') continue;
                        if (cnts[nowx][nowy] + 1 < cnts[nx][ny]) {
                            cnts[nx][ny] = cnts[nowx][nowy] + 1;
                            q.push(P(nx, ny));
                        }
                    }
                }
            }
        }
    }
    if (cnts[endx][endy] == ll_inf) {
        cout << -1 << '\n';
    } else {
        cout << cnts[endx][endy] << '\n';
    }
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
