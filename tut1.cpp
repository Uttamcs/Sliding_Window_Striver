// Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &arr, int k)
{
    int n = arr.size(), lSum = 0, rSum = 0, maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        lSum += arr[i];
    }
    maxSum = lSum;
    int rIndex = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lSum = lSum - arr[i];
        rSum = rSum + arr[rIndex];
        rIndex--;
        maxSum = max(maxSum, lSum + rSum);
    }
    return maxSum;
}
int main()
{
    vector<int>cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxScore(cardPoints, k)<<endl;
    return 0;
}