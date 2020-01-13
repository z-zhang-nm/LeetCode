/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total_size = nums1.size() + nums2.size();
        vector<int> total_nums;
        int nums1_idx = 0, nums2_idx = 0;
        while (nums1_idx < nums1.size() && nums2_idx < nums2.size())
        {
            if (nums1[nums1_idx] <= nums2[nums2_idx])
            {
                total_nums.push_back(nums1[nums1_idx]);
                nums1_idx++;
            }
            else
            {
                total_nums.push_back(nums2[nums2_idx]);
                nums2_idx++;
            }
        }
        while (nums1_idx < nums1.size())
        {
            total_nums.push_back(nums1[nums1_idx]);
            nums1_idx++;
        }
        while (nums2_idx < nums2.size())
        {
            total_nums.push_back(nums2[nums2_idx]);
            nums2_idx++;
        }
        if (total_size % 2 == 0)
        {
            return double(total_nums[total_size / 2 - 1] + total_nums[total_size / 2]) / 2;
        }
        else
        {
            return total_nums[total_size / 2];
        }
    }
};
// @lc code=end
