#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using v = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

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

/* ----------- ANSWER ----------- */
/* ------------------------------ */
string max_s(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) return s1 > s2 ? s1 : s2;
    else return s1.size() > s2.size() ? s1 : s2;
}

// C++ program to find sum of two large numbers.
#include<bits/stdc++.h>

using namespace std;

// Function for finding sum of larger numbers
string findSum(string str1, string str2) {
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string min_s(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) return s1 < s2 ? s1 : s2;
    else return s1.size() < s2.size() ? s1 : s2;
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll l = inl();
        string n = ins();

        v<string> ans;
        rep(i, l) {
            string tmp;
            tmp += n[i];
            while (i + 1 < l && n[i + 1] == '0') {
                i++;
                tmp += n[i];
            }
            ans.eb(tmp);
        }

        ll m = ans.size();

        ll dig = 0;
        string now = ans[0], next;
        int b = 0;
        for (long long i = 1; i < m - 1; ++i) {
            if (dig + ans[i].size() >= m / 2 - 1 && b < 2) {
                b++;
                string tmp1 = findSum(now + ans[i], n.substr(now.size() + ans[i].size()));
                string tmp2 = findSum(now, n.substr(now.size()));


                if (tmp1 != "invalid" && min_s(tmp1, tmp2) == tmp1) {
                    now += ans[i];
                } else {
                    next += ans[i];
                }
            } else if (dig + ans[i].size() > m / 2 - 1) {
                next += ans[i];
            } else {
                now += ans[i];
            }
            dig += ans[i].size();
        }
        next += ans.back();
        cout << findSum(now, next) << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}