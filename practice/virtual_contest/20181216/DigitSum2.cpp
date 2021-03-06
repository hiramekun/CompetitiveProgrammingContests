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
#define inf int(1e9)
#define half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

string n;

void solve() {
    ll ans = 0;
    bool has_no_9 = false;
    repr(i, n.length()) {
        int num = int(n[i] - '0');
        if (i == 0) {
            if (has_no_9) ans += (num - 1);
            else ans += num;
        } else {
            if (num != 9) has_no_9 = true;
            ans += 9;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}
