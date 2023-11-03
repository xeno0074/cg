// https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1127/

// lets convert the subtrees into a string in level order
// null node converts to "."

#include <bits/stdc++.h>

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

// v = [-200, 200]
// v_ = v + 200
// concat v_ digits to string
string getStrVal(int v) { return to_string(v + 200); }

string getKey(TreeNode *root)
{
    if (!root)
    {
        return ".";
    }

    string ret = getStrVal(root->val);

    ret.append(getKey(root->left));
    ret.append(getKey(root->right));

    return ret;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> ret;

        return ret;
    }
};

TreeNode *genTree(const vector<string> &strs)
{
    queue<TreeNode *> q;

    TreeNode *root = new TreeNode(atoi(strs[0].c_str()));

    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.pop();
        }
}

int main()
{
    cout << getStrVal(200) << endl;
    cout << getStrVal(-200) << endl;
    cout << getStrVal(0) << endl;
    cout << getStrVal(95) << endl;
    cout << getStrVal(199) << endl;
}