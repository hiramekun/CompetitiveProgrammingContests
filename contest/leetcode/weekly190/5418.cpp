/**
 * Created by hiramekun at 11:41 on 2020-05-24.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)


//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
    ll ans = 0;

    void dfs(TreeNode *node, vector<ll> &mp) {
        mp[node->val]++;
        ll even = 0, odd = 0;
        if (node->left == nullptr && node->right == nullptr) {
            for (ll i = 1; i <= 9; ++i) {
                if (mp[i] == 0) continue;
                if (mp[i] % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            if (odd == 1 || odd == 0) ans++;
        }
        if (node->left != nullptr) dfs(node->left, mp);
        if (node->right != nullptr) dfs(node->right, mp);
        mp[node->val]--;
    }


    int pseudoPalindromicPaths(TreeNode *root) {
        vector<ll> mp(10, 0);
        dfs(root, mp);
        return ans;
    }
};