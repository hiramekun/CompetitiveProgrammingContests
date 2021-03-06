#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
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
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        printf("? %i %i\n", 1, 2);
        printf("? %i %i\n", 2, 3);
        printf("? %i %i\n", 4, 5);
        printf("? %i %i\n", 4, 6);
        fflush(stdout);

        vl nums(4);
        rep(i, 4) {
            cin >> nums[i];
        }

        ll arr[] = {4, 8, 15, 16, 23, 42};

        do {
            if (arr[0] * arr[1] == nums[0] &&
                arr[1] * arr[2] == nums[1] &&
                arr[3] * arr[4] == nums[2] &&
                arr[3] * arr[5] == nums[3])
                break;
        } while (next_permutation(arr, arr + 6));

        printf("! %lli %lli %lli %lli %lli %lli\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
        fflush(stdout);

#ifdef MY_DEBUG
    }
#endif
    return 0;
}