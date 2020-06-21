/**
 * Created by hiramekun at 11:32 on 2020-06-21.
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
vector<string> split(const string &str, char sep) {
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}

class Solution {
public:
    vector<string> getFolderNames(vector<string> &names) {
        map<string, int> mp;
        vector<string> ret;
        ll n = names.size();
        map<string, int> now;
        rep(i, n) {
            string prefix, num;
            bool is_num = false;
            each(e, names[i]) {
                if (e == '(') is_num = true;
                else if (e == ')') break;
                else {
                    if (is_num) num += e;
                    else prefix += e;
                }
            }
            if (num.empty()) {
                if (mp[prefix] == 0) {
                    mp[prefix]++;
                    ret.eb(prefix);
                } else {
                    string nxt = prefix + '(' + to_string(mp[prefix]) + ')';
                    while (mp[nxt] > 0) nxt = prefix + '(' + to_string(++mp[prefix]) + ')';
                    mp[nxt]++;
                    ret.eb(nxt);
                }
            } else {
                if (mp[names[i]] == 0) {
                    ret.eb(names[i]);
                    mp[names[i]]++;
                } else {
                    string nxt = prefix + '(' + to_string(mp[prefix]) + ')';
                    while (mp[nxt] > 0) nxt = prefix + '(' + to_string(++mp[prefix]) + ')';
                    mp[nxt]++;
                    ret.eb(nxt);
                }
            }
        }

        return ret;
    }
};
