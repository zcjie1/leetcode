/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (44.06%)
 * Likes:    10731
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 4.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode ret = {0, NULL};
    struct ListNode *prev=&ret, *curr=NULL;

    int sum = 0;
    int carry = 0; // 进位
    int result = 0; // 个位

    while(p1 || p2 || carry) {
        sum = (
             (p1 ? p1->val : 0)
            + (p2 ? p2->val : 0) 
            + carry
        );
        carry = sum / 10;
        result = sum % 10;

        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = result;
        curr->next = NULL;

        prev->next = curr;
        prev = curr;

        p1 = p1 ? p1->next : NULL;
        p2 = p2 ? p2->next : NULL;
    }

    return ret.next;
}
// @lc code=end

