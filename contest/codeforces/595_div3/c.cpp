/**
 * Created by hiramekun at 23:30 on 2019-10-22.
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
template<typename TypeInt>
std::string Itoa(const TypeInt v, int base) {
    static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret;
    static numeric_limits<TypeInt> t;
    TypeInt n = v;
    if (t.is_signed) {
        if (v < 0) n *= -1;
    }

    while (n >= base) {
        ret += table[n % base];
        n /= base;
    }
    ret += table[n];
    if (t.is_signed) {
        if (v < 0 && base == 10) ret += '-';
    }
    // 文字列の順番を逆にする
//    std::reverse(ret.begin(), ret.end());

    return ret;
}

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = powmod(x, n / 2, mod);
        return t * t;
    }
    return x * powmod(x, n - 1, mod);
}

void solve() {
    ll q;
    cin >> q;
    rep(_, q) {
        ll n;
        cin >> n;
        string three = Itoa(n, 3);
        ll carry = -1;
        ll idx = -1;
        rep(i, three.size()) {
            if (i + 1 < three.size() && three[i] == '2' && three[i + 1] == '2') {
                carry = i + 2;
            } else if (i + 1 < three.size() && three[i] == '2' && three[i + 1] == '1') {
                carry = i + 2;
            } else if (carry > -1 && (three[i] == '1' || three[i] == '2')) {
                carry = i + 1;
            } else if (three[i] == '2') {
                carry = i + 1;
            } else {
                carry = -1;
            }
            idx = max(idx, carry);
        }
        if (idx == three.size()) {
            cout << powmod(3, idx, mod) << '\n';
        } else {
            ll i = three.size() - 1;
            ll ans = 0;
            if (idx < -1) {
                cout << n << '\n';
                continue;
            }
            while (i > idx) {
                if (three[i] == '1') ans += powmod(3, i, mod);
                i--;
            }
            if (idx >= 0) ans += powmod(3, idx, mod);
            cout << ans << '\n';
        }
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
    
