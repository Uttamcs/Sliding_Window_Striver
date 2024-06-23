// Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int l = 0, r = 0, maxFreq = 0, maxLen = 0;
    vector<int> mpp(26, 0);
    int n = s.size();
    while (r < n)
    {
        mpp[s[r] - 'A']++;
        maxFreq = max(maxFreq, mpp[s[r] - 'A']);
        if ((r - l + 1) - maxFreq > k)
        {
            mpp[s[l] - 'A']--;
            l++;
        }
        if ((r - l + 1) - maxFreq <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}
int main()
{
    string  s = "AABABBA";
    int k = 1;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}