/*
 * @lc app=leetcode.cn id=434 lang=c
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode.cn/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (38.13%)
 * Likes:    226
 * Dislikes: 0
 * Total Accepted:    105.4K
 * Total Submissions: 276.4K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int countSegments(char *s){
    int len = strlen(s);
    int len_count = 0;
    while(*s == ' ') {
        s++;
        len_count++;
    }
        
    int count = 0;
    while(len_count < len) {
        while(*s != ' ') {
            s++;
            len_count++;
            if(len_count >= len)
                break;
        } 
        count++;
        while(*s == ' ') {
            s++;
            len_count++;
            if(len_count >= len)
                break;
        }
            
    }
    return count;
}
// @lc code=end

