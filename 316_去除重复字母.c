/*
 * @lc app=leetcode.cn id=316 lang=c
 *
 * [316] 去除重复字母
 *
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (49.22%)
 * Likes:    1098
 * Dislikes: 0
 * Total Accepted:    144.6K
 * Total Submissions: 293.7K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

char* removeDuplicateLetters(char* s) {
    int vis[26], num[26];
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        num[s[i] - 'a']++;
    }

    char* stk = malloc(sizeof(char) * 27);
    int stkTop = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[s[i] - 'a']) {
            while (stkTop > 0 && stk[stkTop - 1] > s[i]) {
                if (num[stk[stkTop - 1] - 'a'] > 0) {
                    vis[stk[--stkTop] - 'a'] = 0;
                } else {
                    break;
                }
            }
            vis[s[i] - 'a'] = 1;
            stk[stkTop++] = s[i];
        }
        num[s[i] - 'a'] -= 1;
    }
    stk[stkTop] = '\0';
    return stk;
}
// @lc code=end

