//  Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0, right = 0, zeroCnt = 0, maxLen = 0;
    while (right < n)
    {
        if (nums[right] == 0)
            zeroCnt++;
        if (zeroCnt > k)
        {
            if (nums[left] == 0)
                zeroCnt--;
            left++;
        }
        if (zeroCnt <= k)
        {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        right++;
    }
    return maxLen;
}
int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << longestOnes(nums, k) << endl;
    return 0;
}