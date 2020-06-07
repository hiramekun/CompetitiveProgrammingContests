/**
 * Created by hiramekun at 11:55 on 2020-06-07.
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

class Solution {
public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1,
                                       vector<vector<int>>(target + 1,
                                                           vector<int>(n + 1, INT_MAX)));
        rep(i, n) dp[0][0][i] = 0;
        rep(i, m) {
            rep(j, target + 1) {
                rep(prev_col, n) {
                    if (dp[i][j][prev_col] == INT_MAX) continue;

                    if (houses[i] != 0) {
                        ll house_col = houses[i] - 1;
                        if (prev_col == house_col && j != 0) {
                            dp[i + 1][j][house_col] = min(dp[i + 1][j][house_col],
                                                          dp[i][j][prev_col]);
                        } else {
                            if (j + 1 > target) continue;
                            dp[i + 1][j + 1][house_col] = min(dp[i + 1][j + 1][house_col],
                                                              dp[i][j][prev_col]);
                        }
                        continue;
                    }
                    rep(now_col, n) {
                        if (now_col == prev_col && j != 0) {
                            dp[i + 1][j][now_col] = min(dp[i + 1][j][now_col],
                                                        dp[i][j][prev_col] + cost[i][now_col]);
                        } else {
                            if (j + 1 > target) continue;
                            dp[i + 1][j + 1][now_col] = min(dp[i + 1][j + 1][now_col],
                                                            dp[i][j][prev_col] + cost[i][now_col]);
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        rep(i, n) {
            ans = min(ans, dp[m][target][i]);
        }
        if (ans == INT_MAX) ans = -1;
        return ans;
    }
};