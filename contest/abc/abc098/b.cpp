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
#include <numeric>
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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            unordered_map<char, ll> mp1, mp2;
            for (int j = 0; j < i; ++j) {
                mp1[s[j]]++;
            }
            for (int j = i; j < n; ++j) {
                mp2[s[j]]++;
            }
            int tmp = 0;
            each(m1, mp1) {
                each(m2, mp2) {
                    if (m1.first == m2.first) tmp++;
                }
            }
            ans = max(tmp, ans);
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}