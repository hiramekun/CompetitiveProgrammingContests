#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include<bitset>

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

ll N;

void solve() {
    string ans;
    while (N != 0) {
        if (N % 2 != 0) {
            ans = "1" + ans;
            N--;
        } else {
            ans = "0" + ans;
        }
        N /= -2;
    }
    if (ans == "") ans = "0";
    cout << ans << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
