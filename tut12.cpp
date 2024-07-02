// Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int l = 0, r = 0, cnt = 0, sIdx = -1, minLen = INT_MAX;
    unordered_map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[t[i]]++;
    }

    while (r < m)
    {
        if (mpp[s[r]] > 0)
            cnt++;
        mpp[s[r]]--;

        while (cnt == n)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                sIdx = l;
            }

            mpp[s[l]]++;
            if (mpp[s[l]] > 0)
                cnt--;
            l++;
        }
        r++;
    }
    return sIdx == -1 ? "" : s.substr(sIdx, minLen);
}
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}