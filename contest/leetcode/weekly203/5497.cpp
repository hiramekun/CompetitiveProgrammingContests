#ifdef MY_DEBUG
#include <bits/stdc++.h>
using namespace std;
#endif

using ll = long long;
using ld = long double;
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
class UnionFind {
private:
    vector<ll> size;  // グループに属する物の数．
public:
    vector<ll> par;   // 親
    vector<ll> rank;  // 木の深さ
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
    ll calc_size(ll x) { return size[find(x)]; }

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
    bool is_same(ll x, ll y) { return find(x) == find(y); }
};

class Solution {
public:
    int findLatestStep(vector<int> &arr, int m) {
        ll n = arr.size();
        UnionFind u(n + 1);
        vector<bool> show(n + 1);
        map<ll, ll> sizeCnt;

        ll ans = -1;
        for (ll i = 0; i < n; ++i) {
            show[arr[i]] = true;
            if (0 <= arr[i] - 1 && show[arr[i] - 1]) {
                sizeCnt[u.calc_size(arr[i] - 1)]--;
                u.unite(arr[i] - 1, arr[i]);
            }
            if (arr[i] + 1 <= n && show[arr[i] + 1]) {
                sizeCnt[u.calc_size(arr[i] + 1)]--;
                u.unite(arr[i] + 1, arr[i]);
            }
            sizeCnt[u.calc_size(arr[i])]++;
            if (sizeCnt[m] > 0) ans = max(ans, i + 1);
        }
        return ans;
    }
};