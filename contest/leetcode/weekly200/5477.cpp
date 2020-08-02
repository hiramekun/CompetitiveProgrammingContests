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
class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<bool> used(n);
        vector<int> cnts(n);

        int ans = 0;
        for (int row = 0; row < n - 1; ++row) {
            int zerocnt = n - 1 - row;
            auto rec = [&]() -> bool {
                bool has = false;
                for (int x = row; x < n; ++x) {
                    int cnt = 0;
                    for (int y = row + 1; y < n; y++) {
                        if (grid[x][y] == 0) cnt++;
                    }
                    if (cnt == zerocnt) {
                        has = true;
                        for (int x2 = x - 1; x2 >= row; --x2) {
                            swap(grid[x2 + 1], grid[x2]);
                            ans++;
                        }
                        return true;
                    }
                }
                return has;
            };
            if (!rec()) return -1;
        }
        return ans;
    }
};