/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.09%)
 * Likes:    1622
 * Dislikes: 0
 * Total Accepted:    164.8K
 * Total Submissions: 586.7K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        /*方法一(暴力搜索)*/
        if (s.length() <= 1)
        {
            return s;
        }
        int len = s.length(), sub_str_len = s.length();
        while (sub_str_len > 1)
        {
            for (int i = 0; i <= len - sub_str_len; ++i)
            {
                int s_idx = i, e_idx = i + sub_str_len - 1;
                while (s_idx < e_idx)
                {
                    if (s[s_idx] == s[e_idx])
                    {
                        if (s_idx == e_idx - 1 || s_idx == e_idx - 2)
                        {
                            return s.substr(i, sub_str_len);
                        }
                        s_idx++;
                        e_idx--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            sub_str_len -= 1;
        }
        return s.substr(0, 1);
        /*方法二(以每一个字符为中心，向两边扩散)*/
        if (s.size() < 2)
            return s;
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
        /*方法三(动态规划)
        维护一个二维数组dp，其中dp[i][j]表示字符区间[i,j]是否为回文串
        1. 若i=j,则为同一个字符，是长度为1的回文串
        2. 若i=j+1,则为相邻字符，需要判断s[i]是否等于s[j]
        3. 若i-j>=2,则分两种情况，若s[i]等于s[j]且dp[j+1][i-1]等于1,那么dp[i][j]为1，否则为0*/
        if (s.empty())
            return s;
        int n = s.size(), dp[n][n] = {0}, left = 0, maxLen = 1;
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            for (int j = 0; j < i; ++j)
            {
                // if (s[i] == s[j] && (i = j + 1 || dp[j + 1][i - 1]))
                // {
                //     dp[j][i] = 1;
                // }
                // else
                // {
                //     dp[j][i] = 0;
                // }
                //注意i,j的位置不能写反
                dp[j][i] = (s[i] == s[j] && (i == j + 1 || dp[j + 1][i - 1])); //上面的if else可以写为一句
                if (dp[j][i] && i - j + 1 > maxLen)
                {
                    left = j;
                    maxLen = i - j + 1;
                }
            }
        }
        return s.substr(left, maxLen);
    }
    void searchPalindrome(string s, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        if (right - left - 1 > maxLen)
        {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};
// @lc code=end
