// Count number of nice subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/
#include <bits/stdc++.h>
using namespace std;
int lessequaltok(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;

    int l = 0, r = 0, ans = 0, n = nums.size(), sum = 0;

    while (r < n)
    {
        sum += nums[r] % 2;

        while (sum > goal)
        {
            sum -= nums[l] % 2;
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << lessequaltok(nums, k) - lessequaltok(nums, k - 1) << endl;
    return 0;
}