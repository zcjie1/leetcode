/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 找出字符串中第一个匹配项的下标
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (44.03%)
 * Likes:    2270
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0
 * 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
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

void build_next(char *str, int *next, int len) {
    int i = 1;
    int prev_len = 0;
    next[0] = 0;
    while(i < len) {
        if(str[prev_len] == str[i]) {
            prev_len++;
            next[i] = prev_len;
            i++;
        }else {
            if(prev_len == 0) {
                next[i] = 0;
                i++;
            }
            else
                prev_len = next[prev_len-1];
        }
    }
}

int strStr(char* haystack, char* needle) {
    int needlen = strlen(needle);
    int haylen = strlen(haystack);
    int i=0, j=0;

    int next[needlen];

    build_next(needle, next, needlen);

    if(needlen > haylen)
        return -1;

    while(i < haylen) {
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }else if(j>0)
            j = next[j-1];
        else
            i++;
        
        if(j == needlen)
            return i - j;
    }
    return -1;
}
// @lc code=end

