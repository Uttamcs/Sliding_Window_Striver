// Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    int left = 0, right = 0, maxLen = 0, k = 2;
    map<int, int> mapp;
    while (right < n)
    {
        mapp[fruits[right]]++;
        if (mapp.size() > k)
        {
            mapp[fruits[left]]--;
            if (mapp[fruits[left]] == 0)
            {
                mapp.erase(fruits[left]);
            }
            left++;
        }
        if (mapp.size() <= k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}
int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << totalFruit(fruits) << endl;
    return 0;
}