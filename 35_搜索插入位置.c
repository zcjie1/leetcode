/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 *
 * https://leetcode.cn/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (46.78%)
 * Likes:    2363
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 请必须使用时间复杂度为 O(log n) 的算法。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 为 无重复元素 的 升序 排列数组
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define L 0
#define R 1

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int mid = 0;
    int last;

    if(target > nums[numsSize-1])
        return numsSize;
    
    if(target < nums[0])
        return 0;

    while(left <= right) {
        mid = left + (right-left)/2;
        if(nums[mid] < target) {
            left = mid + 1;
            last = L;
            continue;
        }else if(nums[mid] > target) {
            right = mid - 1;
            last = R;
            continue;
        }else {
            return mid;
        }
    }

    if(last == L)
        return left;
    else
        return right+1;

}
// @lc code=end

