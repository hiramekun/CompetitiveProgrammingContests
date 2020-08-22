#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll ll_inf = ll(1e9) * ll(1e9);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll h, w;
    cin >> h >> w;
    ll startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    startX--, startY--, endX--, endY--;

    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    vector<vector<ll>> cnts(h, vector<ll>(w, ll_inf));  // 魔法使った回数
    queue<P> q, visited;
    q.push(P(startX, startY));
    cnts[startX][startY] = 0;

    while (!q.empty() || !visited.empty()) {
        ll nowX, nowY;
        if (!q.empty()) {
            nowX = q.front().first, nowY = q.front().second;
            visited.push(P(nowX, nowY));
            q.pop();
            rep(i, 4) {
                ll nextX = nowX + dx[i], nextY = nowY + dy[i];
                if (0 <= nextX && nextX <= h - 1 && 0 <= nextY && nextY <= w - 1) {
                    if (s[nextX][nextY] == '#') continue;
                    if (cnts[nowX][nowY] < cnts[nextX][nextY]) {
                        cnts[nextX][nextY] = cnts[nowX][nowY];
                        q.push(P(nextX, nextY));
                    }
                }
            }

        } else {  // 今まで通った道から魔法で行ける道を全て調べる
            nowX = visited.front().first, nowY = visited.front().second;
            visited.pop();
            for (ll ix = -2; ix <= 2; ++ix) {
                for (ll jy = -2; jy <= 2; ++jy) {
                    ll nextX = nowX + ix, nextY = nowY + jy;
                    if (0 <= nextX && nextX <= h - 1 && 0 <= nextY && nextY <= w - 1) {
                        if (s[nextX][nextY] == '#') continue;
                        if (cnts[nowX][nowY] + 1 < cnts[nextX][nextY]) {
                            cnts[nextX][nextY] = cnts[nowX][nowY] + 1;
                            q.push(P(nextX, nextY));
                        }
                    }
                }
            }
        }
    }
    if (cnts[endX][endY] == ll_inf) {
        cout << -1 << '\n';
    } else {
        cout << cnts[endX][endY] << '\n';
    }
    return 0;
}
