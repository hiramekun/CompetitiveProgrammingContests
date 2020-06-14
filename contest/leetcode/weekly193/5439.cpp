/**
 * Created by hiramekun at 12:23 on 2020-06-14.
 */
#ifdef MY_DEBUG

#include <bits/stdc++.h>

using namespace std;
#endif

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T>
using pq = priority_queue<T>;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K>
using ump = unordered_map<T, K>;
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
class TreeAncestor {
public:
    vector<int> parent;
    vector<vector<int>> kth_ance;

    TreeAncestor(int n, vector<int> &parent) {
        this->parent = parent;
        ll max_k = 1;
        ll now = 1;
        ll sk = 2 + 10;
        while (now < n + 1) max_k *= 2, now += max_k, sk++;
        kth_ance = vector<vector<int>>(n + 1, vector<int>(sk, -3));
    }

    int getKthAncestor(int node, int k) {
        ll defnode = node;
        if (k > kth_ance[node].size() - 1) return -1;
        if (kth_ance[node][k] != -3) {
            return kth_ance[node][k];
        }
        ll cnt = 0;
        while (node >= 0 && k) {
            k--;
            cnt++;
            kth_ance[defnode][cnt] = parent[node];
            node = parent[node];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */