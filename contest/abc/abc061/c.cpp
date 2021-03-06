#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = int(1e5);
ll N, K, a[MAX_N], b[MAX_N];
map<ll, ll> mp;


void solve() {
    ll times = 0;
    EACH(m, mp) {
        times += m.second;
        if (times >= K) {
            cout << m.first << endl;
            return;
        }
    }
}

int main() {
    cin >> N >> K;
    REP(i, N) {
        cin >> a[i] >> b[i];
        mp[a[i]] += b[i];
    }
    solve();
    return 0;
}
