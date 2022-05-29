#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        bool rev = true;
        while (!q.empty())
        {
            int si = q.size();
            vector<int> t;
            for (int i = 0; i < si; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                t.push_back(cur->val);
                if (cur->left)
                {
                    q.push(cur->left);
                }

                if (cur->right)
                {
                    q.push(cur->right);
                }
            }

            if (rev == true)
            {
                ans.push_back(t);
            }
            else
            {
                reverse(t.begin(), t.end());
                ans.push_back(t);
            }
            rev = !rev;
        }

        return ans;
    }
};