/**
 * Created by hiramekun at 20:51 on 2020-04-04.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll k;
    cin >> k;
    vector<ll> a;
    for (ll i = 1; i <= 9; ++i) a.emplace_back(i);

    while (k > a.size()) {
        k -= a.size();
        vector<ll> old = a;
        a = vector<ll>();
        for (ll x: old) {
            for (ll i = -1; i <= 1; ++i) {
                ll d = x % 10 + i;
                if (d < 0 || 9 < d) continue;
                ll nx = x * 10 + d;
                a.emplace_back(nx);
            }
        }
    }
    cout << a[k - 1] << '\n';
    return 0;
}
