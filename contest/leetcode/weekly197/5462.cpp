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
struct edge {
    ll from, to;
    double cost;

    edge(ll from, ll to, double cost) : from(from), to(to), cost(cost){};
};

typedef vector<edge> ve;
typedef vector<ve> vve;

class Graph {
private:
    ll v;
    vve table;
    vector<double> d;
    vl pre;  // 最短路の直前の頂点
    ve edges;

public:
    // v: 頂点数
    explicit Graph(ll v) : v(v) {
        table.resize(v);
        pre.resize(v, -1);
        d.resize(v, 0);
    }

    void add(ll from, ll to, double cost = 1) {
        edge e1(from, to, cost);
        table[from].emplace_back(e1);
        edges.emplace_back(e1);
    }

    // O(v + e)
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    vl sort() {
        stack<ll> st;  // 入力次数が0の頂点集合
        vl in_d(v);
        for (const auto ele : edges) {
            in_d[ele.to]++;
        }

        rep(i, v) if (in_d[i] == 0) { st.push(i); }
        vl ans;  // ソート後のグラフ

        while (!st.empty()) {
            ll i = st.top();
            st.pop();
            ans.emplace_back(i);
            for (const auto j : table[i]) {
                ll to = j.to;
                in_d[to]--;
                if (in_d[to] == 0) st.push(to);
            }
        }

        return move(ans);
    }

    // O(v + e)
    // 閉路が存在するときは-1を返す
    double get_longest_path() {
        vector<bool> seen(v), calc(v);
        vector<double> d(v, 0);
        auto dfs = [&](auto &&f, ll now) -> ll {
            if (seen[now]) {
                if (!calc[now]) return -1;
                return d[now];
            }
            seen[now] = true;
            d[now] = 1;
            for (const auto &t : table[now]) {
                ll res = f(f, t.to);
                if (res == -1) return -1;
                d[now] = max(res + t.cost, d[now]);
            }
            calc[now] = true;
            return d[now];
        };

        ll ans = 0;
        rep(i, v) {
            ll tmp = dfs(dfs, i);
            if (tmp == -1) {
                return -1;
            }
            ans = max(tmp, ans);
        }
        return ans;
    }

    // 負の重みがあっても動く
    // O(v * e)
    vector<double> bellman_ford(ll s) {
        d[s] = 0;
        rep(_, v - 1) {
            for (const auto &e1 : edges) {
                if (d[e1.from] != ll_inf && d[e1.to] > d[e1.from] + e1.cost) {
                    d[e1.to] = d[e1.from] + e1.cost;
                }
            }
        }
        return d;
    }

    // 各頂点までに到達する経路中に負の閉路が存在するか
    // bellman_fortで最短経路を出した後に使う
    vl has_negative_loop_in_path() {
        vl has_loop(v, false);
        rep(_, v - 1) {
            for (const auto &e1 : edges) {
                if (d[e1.to] > d[e1.from] + e1.cost) {
                    has_loop[e1.from] = true;
                }
                if (has_loop[e1.from]) {
                    has_loop[e1.to] = true;
                }
            }
        }
        return move(has_loop);
    }

    // O(e * logv)
    vector<double> dijkstra(ll s) {
        // pairを使っているのは、比較関数を利用するため
        priority_queue<pair<double, double>, vector<pair<double, double>>> que;
        d[s] = 1;
        que.push(pair<double, double>(1, s));

        while (!que.empty()) {
            pair<double, double> p = que.top();
            que.pop();
            ll min_v = p.second;
            if (d[min_v] > p.first) continue;
            for (const auto &ele : table[min_v]) {
                if (d[ele.to] < d[min_v] * ele.cost) {
                    d[ele.to] = d[min_v] * ele.cost;
                    pre[ele.to] = min_v;
                    que.push(pair<double, double>(d[ele.to], ele.to));
                }
            }
        }
        return d;
    }

    // 頂点tへの最短路
    // dijkstraで最短経路を出した後に使う
    vector<int> get_path(int t) {
        vector<int> path;
        for (; t != -1; t = pre[t]) path.emplace_back(t);  // tがsになるまでpre[t]をたどっていく
        reverse(path.begin(), path.end());
        return move(path);
    }

    // 頂点sからの閉路検出
    // もし閉路がないならば v + 1の大きさのベクトルを返す。
    vl cyclic(ll s) {
        queue<ll> que;
        que.push(s);
        pre.assign(v, -1);
        d.assign(v, ll_inf);
        d[s] = 0;
        while (!que.empty()) {
            ll now = que.front();
            que.pop();
            each(e, table[now]) {
                if (d[e.to] != ll_inf) continue;
                d[e.to] = d[e.from] + 1;
                pre[e.to] = e.from;
                que.push(e.to);
            }
        }

        P best(ll_inf, -1);
        rep(i, v) {
            if (i == s) continue;
            each(e, table[i]) {
                if (e.to == s) {
                    best = min(best, {d[e.from], e.from});
                }
            }
        }
        if (best.first == ll_inf) return vl(v + 1);
        vl ret;
        ll now = best.second;
        while (now != -1) {
            ret.emplace_back(now + 1);
            now = pre[now];
        }
        return ret;
    }

    // 二部グラフ判定
    bool bipartite() {
        vl ids(v, -1);
        auto dfs = [&](auto &&f, ll s, ll id) -> bool {
            if (ids[s] == -1) {
                ids[s] = id;
            } else {
                return ids[s] != id;
            }
            each(e, table[s]) {
                if (f(f, e.to, 1 - id)) return true;
            }
            return false;
        };
        return dfs(dfs, 0, 1);
    };
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        Graph g(n);
        rep(i, edges.size()) {
            ll a = edges[i][0], b = edges[i][1];
            g.add(a, b, succProb[i]);
            g.add(b, a, succProb[i]);
        }
        return g.dijkstra(start)[end];
    }
};