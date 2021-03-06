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
#define i_inf int(1e9)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N;

void solve() {
    repone(h, 3500) {
        repone(w, 3500) {
            double temp = double(N * h * w) / double(4 * h * w - N * h - N * w);
            auto t = temp - ll(temp);
            if (t == 0 && ll(temp) > 0) {
                printf("%lli %lli %lli", h, ll(temp), w);
                return;
            }
        }
    }
}

int main() {
    cin >> N;
    solve();
    return 0;
}
