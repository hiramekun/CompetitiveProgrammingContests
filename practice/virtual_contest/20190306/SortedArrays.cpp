#include <cstring>
#include <sstream>
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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

void solve() {
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];

        ll ans = ll_inf;
        rep(i, 2) {
            bool increase = i;
            bool reset = false;
            ll temp = 1;
            ll idx = 0;
            while (idx + 1 < n) {
                if (a[idx + 1] == a[idx]) {
                    idx++;
                    continue;
                }
                if (reset) {
                    increase = a[idx + 1] > a[idx];
                    idx++, reset = false;
                    continue;
                }
                if (a[idx + 1] >= a[idx] && increase) idx++;
                else if (a[idx + 1] <= a[idx] && !increase) idx++;
                else if (a[idx + 1] < a[idx] && increase) {
                    increase = false, idx++;
                    reset = true;
                    temp++;
                } else if (a[idx + 1] > a[idx] && !increase) {
                    increase = true, idx++;
                    reset = true;
                    temp++;
                }
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}