#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> infan_group(n);
    vector<set<ll>> group_infan(2e5);
    vector<multiset<ll>> group_rate(2e5);
    vector<ll> rate(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        b--;
        infan_group[i] = b;
        group_infan[b].insert(i);
        group_rate[b].insert(a);
        rate[i] = a;
    }
    multiset<ll> maxs;
    rep(i, 2e5) {
        if (group_rate[i].empty()) continue;
        maxs.insert(*group_rate[i].rbegin());
    }

    rep(i, q) {
        ll infant_id, new_group;
        cin >> infant_id >> new_group;
        infant_id--, new_group--;
        ll group = infan_group[infant_id];
        ll r = rate[infant_id];

        // 異動前のグループで最高レートだった場合、最高のグループからのぞく
        bool tmp = false;
        if (*group_rate[group].find(r) == *(group_rate[group].rbegin())) {
            maxs.erase(maxs.find(r));
            tmp = true;
        }
        // 昔のレートをこのグループから除く
        group_rate[group].erase(group_rate[group].find(r));

        // 昔のグループが空でない、かつ、昔のグループで最高レートのものを移動した場合、新しいものを最高レートグループに入れる
        if (tmp && !group_rate[group].empty()) {
            maxs.insert(*group_rate[group].rbegin());
        }

        // 新しいグループが空だったら、移動したレートが最高レートグループに入る
        if (group_rate[new_group].empty()) {
            maxs.insert(r);
        } else {
            // 新しいグループが空じゃなくても、現在の最高レートよりも上だったら、最高レートグループを更新する
            if (*group_rate[new_group].rbegin() < r) {
                ll t = *group_rate[new_group].rbegin();
                maxs.erase(maxs.find(t));
                maxs.insert(r);
            }
        }
        // 新しいグループにレートを移動する
        group_rate[new_group].insert(r);
        // 園児を移動する
        infan_group[infant_id] = new_group;
        cout << *maxs.begin() << '\n';
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
