// Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int c = 0;
    unordered_map<int, int> mpp;
    while (j < nums.size())
    {
        mpp[nums[j]]++;
        while (i <= j && mpp.size() > k)
        {
            if (--mpp[nums[i]] == 0)
                mpp.erase(nums[i]);
            i++;
        }
        c += j - i + 1;
        j++;
    }
    return c;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4};
    int k = 3;
    cout << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}