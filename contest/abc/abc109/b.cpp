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


const int MAX_N = 100;
int N;
string W[MAX_N];

void solve() {
    REP(i, N) {
        REP(j, N) {
            if (i != j && W[i] == W[j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    char before = ' ';
    REP(i, N) {
        if (i != 0) {
            if (W[i][0] != before) {
                cout << "No" << endl;
                return;
            }
            before = W[i][W[i].length() - 1];
        } else {
            before = W[i][W[i].length() - 1];
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> W[i];
    solve();
    return 0;
}
