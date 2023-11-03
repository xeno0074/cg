// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1115/

#include <bits/stdc++.h>

using namespace std;

class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> h;
        int n = nums.size();
        vector<int> ret;

        for (int i = 0; i < n; ++i)
        {
            int diff = target - nums[i];

            if (h.count(nums[i]) > 0)
            {
                ret.push_back(h[nums[i]]);
                ret.push_back(i);

                return ret;
            }

            h.insert(make_pair(diff, i));
        }

        return ret;
    }
};

class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        vector<int> ret;

        for (int i = 0; i < n; ++i)
        {
            hashmap.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < n; ++i)
        {
            int t = target - nums[i];

            if (hashmap.count(t) > 0 && hashmap[t] != i)
            {
                if (hashmap[t] > i)
                {
                    ret.emplace_back(i);
                    ret.emplace_back(hashmap[t]);
                }
                else
                {
                    ret.emplace_back(hashmap[t]);
                    ret.emplace_back(i);
                }
                return ret;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> v1{2, 7, 11, 15};
    int target1 = 9;

    vector<int> v2{3, 2, 4};
    int target2 = 6;

    vector<int> v3{3, 3};
    int target3 = 6;

    Solution2 s;
    vector<int> res = s.twoSum(v2, target2);

    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}