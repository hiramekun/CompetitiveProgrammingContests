#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll m, ll n) {
    if ((0 == m) || (0 == n)) return 0;
    return ((m / gcd(m, n)) * n);
}
// 素因数分解
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> mp;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) mp[n]++;
    return mp;
}
// 素数判定
bool is_prime(ll n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}
// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}
ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = powmod(x, n / 2, mod);
        return t * t % mod;
    }
    return x * powmod(x, n - 1, mod) % mod;
}
template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 x;

    constexpr modint(const u64 x = 0) noexcept : x(x % Modulus) {}

    constexpr u64 &value() noexcept { return x; }

    constexpr const u64 &value() const noexcept { return x; }

    constexpr modint operator+(const modint rhs) const noexcept { return modint(*this) += rhs; }

    constexpr modint operator-(const modint rhs) const noexcept { return modint(*this) -= rhs; }

    constexpr modint operator*(const modint rhs) const noexcept { return modint(*this) *= rhs; }

    constexpr modint operator/(const modint rhs) const noexcept { return modint(*this) /= rhs; }

    constexpr modint &operator+=(const modint rhs) noexcept {
        x += rhs.x;
        if (x >= Modulus) {
            x -= Modulus;
        }
        return *this;
    }

    constexpr modint &operator-=(const modint rhs) noexcept {
        if (x < rhs.x) {
            x += Modulus;
        }
        x -= rhs.x;
        return *this;
    }

    constexpr modint &operator*=(const modint rhs) noexcept {
        x = x * rhs.x % Modulus;
        return *this;
    }

    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

typedef vector<modint<mod>> vmod;
typedef vector<vmod> vvmod;
// n以下の素数を返す
vector<ll> sieve(ll n) {
    vector<ll> prime;
    vector<bool> is_prime;
    is_prime.resize(n + 1);
    prime.resize(n);
    ll p = 0;
    rep(i, n + 1) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < n + 1; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            cout << p << '\n';
            for (ll j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return prime;
}
vl SieveOfEratosthenes(int n) {
    vl ret;
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]) ret.eb(p);
    return ret;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    modint<mod> ans = 0;
    vl mods = SieveOfEratosthenes(k);
    sort(all(mods));
    reverse(all(mods));

    modint<mod> cn = 0;
    each(e, mods) {
        ll cnt = k / e;
        for (ll i = cnt; i >= 1; i--) {
            cn += powmod(i, n, mod);
            cn -= powmod(i - 1, n, mod);
            modint<mod> tmp = (powmod(i, n, mod) * e % mod);
            tmp -= (powmod(i - 1, n, mod) * e % mod);
            ans += tmp;
        }
    }
    ans += powmod(k, n, mod);
    ans -= cn;;
    cout << ans.x << '\n';
}

int main() {
    solve();
    return 0;
}
