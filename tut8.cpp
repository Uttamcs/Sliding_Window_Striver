// Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/description/
#include <bits/stdc++.h>
using namespace std;
int lessequaltok(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;

    int l = 0, r = 0, ans = 0, n = nums.size(), sum = 0;

    while (r < n)
    {
        sum += nums[r];

        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        ans += (r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << lessequaltok(nums, goal) - lessequaltok(nums, goal - 1) << endl;
    return 0;
}