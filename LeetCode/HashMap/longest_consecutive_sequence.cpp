// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

struct RangeData
{
    int count;
    int start;
    int end;
};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, RangeData> mp;
        int maxCount = 0;

        for (int num : nums)
        {
            // insert the num to map if it doesn't exist
            // join on either side of range if found and update the start and end of ranges on either side

            if (mp.count(num) > 0)
            {
                continue;
            }

            int l = num - 1;
            int r = num + 1;
            RangeData rd{1, num, num};

            if (mp.count(l) > 0)
            {
                // left range exists hence merge on the left
                rd.start = mp[l].start;
                rd.count += mp[l].count;
            }

            if (mp.count(r) > 0)
            {
                // right range exists hence merge on the right
                rd.end = mp[r].end;
                rd.count += mp[r].count;
            }

            // insert the range data on the current element
            mp[num] = rd;

            if (mp.count(l) > 0)
            {
                // insert the range data on the left end
                mp[mp[l].start] = rd;
            }

            if (mp.count(r) > 0)
            {
                // insert the range data on the right end
                mp[mp[r].end] = rd;
            }

            maxCount = max(maxCount, rd.count);
        }

        return maxCount;
    }
};

int main()
{
    vector<int> v1{100, 4, 200, 1, 3, 2, 6, 0, 5, 10};

    Solution sol;

    cout << sol.longestConsecutive(v1) << endl;

    return 0;
}