#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    if (s.length() == 1)
    {
        return 1;
    }
    unordered_set<char> c_set{s[0]};
    int s_idx = 0, e_idx = 1;
    int max_len = 1;
    while (e_idx < s.length())
    {
        if (c_set.count(s[e_idx]))
        {
            if ((e_idx - s_idx) > max_len)
            {
                max_len = e_idx - s_idx;
            }
            c_set.erase(s[s_idx]);
            s_idx += 1;
        }
        else
        {
            c_set.insert(s[e_idx]);
            e_idx += 1;
        }
    }
    if ((e_idx - s_idx) > max_len)
    {
        max_len = e_idx - s_idx;
    }
    return max_len;
}

int main()
{
    string s = "au";
    int ret = lengthOfLongestSubstring(s);
    cout << ret << endl;
}