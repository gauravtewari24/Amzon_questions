// Unique
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        set<vector<int>> s;
        int i = 0;
        int j = i + 1;
        int k = i + 2;
        for (i; i < nums.size(); i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }

        for (auto a : s)
        {
            v.push_back(a);
        }
        return v;
    }
};