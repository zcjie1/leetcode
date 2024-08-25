/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (54.02%)
 * Likes:    1148
 * Dislikes: 0
 * Total Accepted:    718.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev;
    struct ListNode *next;
    struct ListNode *p = head;

    if(!p)
        return NULL;

    prev = p;
    p = p->next;
    while(p != NULL) {
        if(p->val == prev->val) {
            next = p->next;
            prev->next = next;
            free(p);
            p = prev;
        }
        prev = p;
        p = p->next;
    }
    return head;

}
// @lc code=end

