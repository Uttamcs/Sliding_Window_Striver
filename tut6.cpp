// 1358. Number of Substrings Containing All Three Characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    int n = s.size();
    int cnt = 0;
    vector<int> lastSeen(3, -1);
    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
    }
    return cnt;
}
int main()
{
    string  s = "abcabc";
    cout<<numberOfSubstrings(s)<<endl;
    return 0;
}