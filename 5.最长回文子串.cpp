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
    }
};
// @lc code=end
