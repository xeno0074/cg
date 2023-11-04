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

struct MapVal
{
    bool inserted;
    TreeNode *node;
};

unordered_map<string, MapVal> mp;
vector<TreeNode *> vt;

string dfs(TreeNode *root)
{
    if (root == nullptr)
    {
        return ".";
    }

    string ret = to_string(root->val);
    ret.append(",");
    ret.append(dfs(root->left));
    ret.append(",");
    ret.append(dfs(root->right));
    ret.append(",");

    cout << "converted string: " << ret << endl;

    if (mp.count(ret) > 0)
    {
        if (mp[ret].inserted == false)
        {
            vt.emplace_back(root);
            mp[ret].inserted = true;
        }
    }
    else
    {
        mp[ret] = MapVal{false, root};
    }

    return ret;
}

class Solution
{
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        mp.clear();
        vt.clear();
        dfs(root);

        return vt;
    }
};

void dfsp(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    dfsp(root->left);
    dfsp(root->right);
}

void printvtn()
{
    for (TreeNode *p : vt)
    {
        dfsp(p);
    }

    cout << endl;
}

int main()
{
    TreeNode root(1), e12(2), e13(3), e124(4), e132(2), e134(4), e1324(4);
    root.left = &e12;
    root.right = &e13;
    e12.left = &e124;
    e13.left = &e132;
    e13.right = &e134;
    e132.left = &e1324;

    Solution sol;
    sol.findDuplicateSubtrees(&root);

    printvtn();
}