// Longest K unique characters substring
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    int left = 0, right = 0, maxLen = 0, n = s.size();
    map<char, int> mpp;
    while (right < n)
    {
        mpp[s[right]]++;
        if (mpp.size() > k)
        {
            mpp[s[left]]--;
            if (mpp[s[left]] == 0)
            {
                mpp.erase(s[left]);
            }
            left++;
        }
        else if (mpp.size() == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    if (maxLen == 0)
        return -1;
    return maxLen;
}
int main()
{
    string S = "aabacbebebe";
    int K = 3;
    cout<<longestKSubstr(S, K)<<endl;
    return 0;
}