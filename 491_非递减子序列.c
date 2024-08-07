/*
 * @lc app=leetcode.cn id=491 lang=c
 *
 * [491] 非递减子序列
 *
 * https://leetcode.cn/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (51.97%)
 * Likes:    798
 * Dislikes: 0
 * Total Accepted:    193K
 * Total Submissions: 371.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool isPowerOfTwo(int num) {
    if (num <= 0) 
        return false;
    return (num & (num - 1)) == 0;
}

// 数字变为 0/1 数组
void num_to_array(int n, int *ret, int len)
{
    int count = 0;
    while(count < len) {
        ret[count] = n & 1;
        n = n >> 1;
        count++;
    }
}

// len >= 2
bool is_ascend(int *nums, int len)
{
    int count = 1;
    while(count < len) {
        if(nums[count] < nums[count-1])
            return false;
        count++;
    }
    return true;
}

bool is_again_insert(int *tmp, int tlen, int **ret, int rlen, int *column_len)
{
    return true;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret = (int **)malloc(sizeof(int*) * 32768);
    *returnColumnSizes = (int *)malloc(sizeof(int *) * 32768);
    // returnSize = (int *)malloc(sizeof(int));
    int selected[numsSize];
    int tmp[numsSize];
    int tmp_index = 0;

    int max = (int)(pow(2, (double)numsSize) - 1);

    for(int i=3; i<max; i++) {
        if(isPowerOfTwo(i))
            continue;
        // num_to_array(i, selected, numsSize);
        
        // select the subsequence
        int n = i;
        for(int j=0; j<numsSize; j++) {
            if (n & 1) {
                tmp[tmp_index++] = nums[j];
                n = n >> 1;
            }else {
                n = n >> 1;
            }
        }

        // is ascend?
        if(is_ascend(tmp, tmp_index) 
            && is_again_insert(tmp, tmp_index, ret, *returnSize, *returnColumnSizes)) {
            (*returnSize)++;
            ret[(*returnSize)-1] = (int *)malloc(sizeof(int) * tmp_index);
            (*returnColumnSizes)[(*returnSize)-1] = (int *)malloc(sizeof(int));

            for(int j=0; j<tmp_index; j++)
                ret[(*returnSize)-1][j] = tmp[j];
            (*returnColumnSizes)[(*returnSize)-1] = tmp_index;
        }

        tmp_index = 0;
    }

    return ret;
}
// @lc code=end

