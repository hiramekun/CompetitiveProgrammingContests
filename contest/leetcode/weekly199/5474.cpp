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
#ifdef MY_DEBUG
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    int countPairs(TreeNode *root, int distance) {
        int ans = 0;

        auto rec = [&](auto &&f, TreeNode *node) -> vector<int> {
            // そもそもノードが存在しない
            if (node == nullptr) return {0};
            // 葉
            if (node->left == nullptr && node->right == nullptr) return {1};
            vector<int> l = f(f, node->left);
            vector<int> r = f(f, node->right);
            for (const auto &a : l) {
                for (const auto &b : r) {
                    // 右側と左側の距離を足して、条件を満たすか
                    if (a && b && a + b <= distance) ans++;
                }
            }
            vector<int> ret;

            // 親ノードへの伝播
            for (const auto &a : l) {
                if (a && a + 1 < distance) ret.emplace_back(a + 1);
            }
            for (const auto &b : r) {
                if (b && b + 1 < distance) ret.emplace_back(b + 1);
            }
            return ret;
        };

        rec(rec, root);
        return ans;
    }
};