//
// Created by Takaaki Hirano on 2018/09/05.
//
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


void solve() {
}

int main() {
    string S;
    cin >> S;
    int ans = 700;
    REP(i, 3)if (S[i] == 'o') ans += 100;
    cout << ans << endl;
    return 0;
}
