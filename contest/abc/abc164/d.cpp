/**
 * Created by hiramekun at 20:53 on 2020-04-26.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define each(i, mp) for(auto& i:mp)

int main() {
    string s;
    cin >> s;
    map<ll, ll> mp;
    mp[0] = 1;
    reverse(s.begin(), s.end());
    ll now = 0, ten = 1;
    each(e, s) {
        now = (now + (e - '0') * ten) % 2019;
        ten *= 10;
        ten %= 2019;
        mp[now]++;
    }
    ll ans = 0;
    each(e, mp) {
        ans += e.second * (e.second - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
