// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    vector<int> visited(255, -1);
    int l = 0, r = 0, maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[s[i]] != -1)
        {
            if (visited[s[i]] >= l)
            {
                l = visited[s[i]] + 1;
            }
        }
        int len = r - l + 1;
        visited[s[i]] = i;
        r++;
        maxLen = max(maxLen, len);
    }
    return maxLen;
}
int main()
{
    string s =  "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}