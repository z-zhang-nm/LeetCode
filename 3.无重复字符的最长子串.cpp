/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.47%)
 * Likes:    2998
 * Dislikes: 0
 * Total Accepted:    318.3K
 * Total Submissions: 980K
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
//优化的滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> idx_map;
        int s_idx = 0, e_idx = 0;
        int len = 0;
        while (e_idx < s.length())
        {
            if (idx_map.count(s[e_idx]) && idx_map[s[e_idx]] >= s_idx) //加条件idx_map[s[e_idx]] > s_idx是因为tmmzuxt这种情况
            {
                s_idx = idx_map[s[e_idx]] + 1;
            }
            idx_map[s[e_idx]] = e_idx; //自增优先级比赋值高，不能写为idx_map[s[e_idx]] = e_idx++
            e_idx++;
            len = max(e_idx - s_idx, len);
        }
        return len;
    }
};
// @lc code=end
