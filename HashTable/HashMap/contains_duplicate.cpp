// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1121/

#include <bits/stdc++.h>

using namespace std;

class BfSolution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] == nums[j])
                {
                    if (j - i <= k)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> indexMap;

        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (indexMap.count(nums[i]) > 0)
            {
                if (i - indexMap[nums[i]] <= k)
                {
                    return true;
                }
                else
                {
                    indexMap[nums[i]] = i;
                }
            }
            else
            {
                indexMap[nums[i]] = i;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums{9, 4, 9, 8, 4};
    Solution sol;
    BfSolution bfSol;

    cout << bfSol.containsNearbyDuplicate(nums, 2) << "\n";
    cout << sol.containsNearbyDuplicate(nums, 2) << "\n";

    return 0;
}