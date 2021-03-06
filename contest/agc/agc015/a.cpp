#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n, a, b;


void solve() {
    unordered_map<ll, ll> mp;
    if (b < a) cout << 0 << endl;
    else if (n == 1 && a != b) cout << 0 << endl;
    else if (a == b) cout << 1 << endl;
    else {
        cout << (n - 2) * (b - a) + 1 << endl;
    }
}

int main() {
    cin >> n >> a >> b;
    solve();
    return 0;
}
