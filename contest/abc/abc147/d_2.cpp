/**
 * Created by hiramekun at 23:02 on 2019-12-08.
 */
#include <bits/stdc++.h>

#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

ll modpow(ll a, ll p) {
    if (p == 0)
        return 1;
    if (p % 2 == 0) {
        ll halfp = p / 2;
        ll half = modpow(a, halfp);
        return half * half % MOD;
    } else {
        return a * modpow(a, p - 1) % MOD;
    }
}

template<std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 x;

    constexpr modint(const u64 x = 0) noexcept : x(x % Modulus) {}

    constexpr u64 &value() noexcept { return x; }

    constexpr const u64 &value() const noexcept { return x; }

    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }

    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }

    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }

    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }

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

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    map<int, int> cnt;
    REP(i, N) {
        cin >> A[i];
        REP(j, 61) {
            if (!(A[i] & (1LL << j))) {
                cnt[j]++;
            }
        }
    }
    modint<MOD> ans = 0LL;
    REP(i, N) {
        REP(j, 61) {
            if (A[i] & (1LL << j)) {
                // flagが立っていたら
                // cout << i << " hoge" << j << ":" << cnt[j] << endl;
                ans += modpow(2, j) * cnt[j];
            } else {
                ans += modpow(2, j) * (N - cnt[j]);
            }
        }
    }
    ans /= 2;
    cout << ans.x << endl;
    return 0;
}
