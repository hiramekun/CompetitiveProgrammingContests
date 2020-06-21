/**
 * Created by hiramekun at 12:02 on 2020-06-21.
 */
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
    vector<int> avoidFlood(vector<int> &rains) {
        int n = rains.size();
        vector<int> v(n);

        // 「空にする日」を入れておく
        set<int> drydays;

        // full_lakes[i]: 今までで、湖iを水で満たした最後の日を持つ
        unordered_map<int, int> full_lakes;

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                drydays.insert(i);
                // 適当に入れる。後で書き換わる可能性あり
                v[i] = 1;
            } else {
                if (full_lakes.find(rains[i]) == full_lakes.end()) {
                    full_lakes[rains[i]] = i;
                } else {
                    if (drydays.empty()) return vector<int>();

                    // 前回に湖を満たした日を求める
                    int prev = full_lakes[rains[i]];

                    // prev以降でもっとも近いところに存在する、「空にする日」を探して、
                    // 空にする日はrains[i]を空にすることにする
                    auto itr = drydays.lower_bound(prev);
                    if (itr == drydays.end()) {
                        return vector<int>();
                    } else {
                        v[*itr] = rains[i];
                        drydays.erase(*itr);

                        // 湖を満たした日をアップデートする
                        full_lakes[rains[i]] = i;
                    }

                }
                v[i] = -1;
            }
        }

        return v;
    }
};