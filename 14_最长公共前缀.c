/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.22%)
 * Likes:    3159
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define CHAR_SIZE sizeof(char)

char* longestCommonPrefix(char** strs, int strsSize) {
    char *ret = (char *)malloc(CHAR_SIZE * 200);
    int count = 0;
    char tmp;

    while(1) {
        tmp = strs[0][count];
        if(tmp == '\0') {
            ret[count] = '\0';
            return ret;
        }
        for(int i=1; i<strsSize; i++) {
            if(strs[i][count] == tmp )
                continue;
            ret[count] = '\0';
            return ret;
        }
        ret[count] = tmp;
        count++;
    }
}
// @lc code=end

