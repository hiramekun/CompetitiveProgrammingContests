#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main() {
    int N, M;
    cin >> N;
    map<string, int> s;
    string temp;
    REP(i, N) {
        cin >> temp;
        s[temp]++;
    }
    cin >> M;
    string t[M];
    REP(i, M) {
        cin >> t[i];
        if (s[t[i]] != 0) s[t[i]]--;
    }
    int ans = 0;
    EACH(i, s) ans = max(ans, i.second);
    cout << ans << endl;
    return 0;
}
