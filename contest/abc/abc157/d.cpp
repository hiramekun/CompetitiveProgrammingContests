/**
 * Created by hiramekun at 02:12 on 2020-05-10.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
class UnionFind {
private:
    vector<ll> size; // グループに属する物の数．
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ
    ll groupCount;

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        groupCount = n;
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    // 木の根を求める
    ll find(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // グループのサイズを求める．
    ll calc_size(ll x) {
        return size[find(x)];
    }

    // xとyの属する集合を併合
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        groupCount--;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        size[x] = size[y] = size[x] + size[y];
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> g[n];
    UnionFind u(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].eb(b);
        g[b].eb(a);
        u.unite(a, b);
    }
    vector<ll> ans(n);
    rep(i, n) {
        ans[i] = u.calc_size(i) - 1;
        ans[i] -= g[i].size();
    }
    rep(i, k) {
        ll c, d;
        cin >> c >> d;
        c--, d--;
        if (u.is_same(c, d)) {
            ans[c]--, ans[d]--;
        }
    }
    cout << ans << '\n';
}

void solve2() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> g[n];
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].eb(b);
        g[b].eb(a);
    }

    vector<bool> seen(n), seen2(n);
    ll con_cnt = -1;
    auto rec = [&seen, &con_cnt, &g](auto &&f, ll now) -> void {
        con_cnt++;
        seen[now] = true;
        each(e, g[now]) {
            if (seen[e]) continue;
            f(f, e);
        }
    };
    vl ans(n), group(n);
    ll group_code = 1;
    auto rec2 = [&seen2, &group, &g, &group_code, &ans, &con_cnt](auto &&f, ll now) -> void {
        group[now] = group_code;
        ans[now] = con_cnt - g[now].size();
        seen2[now] = true;
        each(e, g[now]) {
            if (seen2[e]) continue;
            f(f, e);
        }
    };
    rep(i, n) {
        if (seen[i]) continue;
        con_cnt = -1;
        rec(rec, i);
        rec2(rec2, i);
        group_code++;
    }
    rep(i, k) {
        ll c, d;
        cin >> c >> d;
        c--, d--;
        if (group[c] == group[d]) {
            ans[c]--, ans[d]--;
        }
    }
    cout << ans << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve2();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
