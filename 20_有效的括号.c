/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.11%)
 * Likes:    4519
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.3M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
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

bool isValid(char* s) {
    int len = strlen(s);
    int i = -1;
    char stk[10000];
    int top = 0;

    while(++i < len) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            stk[top++] = s[i];
            continue;
        }else {
            if(top == 0)
                return false;
            switch(s[i]) {
                case ')':
                if(stk[top-1] != '(')
                    return false;
                break;
                
                case ']':
                if(stk[top-1] != '[')
                    return false;
                break;
                
                case '}':
                if(stk[top-1] != '{')
                    return false;
                break;

                default: break;
            }
            top--;
        }
        
    }
    
    if(top == 0)
        return true;
    else
        return false;
}
// @lc code=end

