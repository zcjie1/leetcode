/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.81%)
 * Likes:    3568
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
 */

// @lc code=start

// Definition for singly-linked list
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode head = {0, NULL};
    struct ListNode *p1 = list1;
    struct ListNode *p2 = list2;
    struct ListNode *curr = &head;

    while(p1 || p2) {
        if(!p1) {
            curr->next = p2;
            break;
        }

        if(!p2) {
            curr->next = p1;
            break;
        }

        if(p1->val <= p2->val) {
            // curr = (struct ListNode *)malloc(sizeof(struct ListNode));
            curr->next = p1;
            curr = p1;
            p1 = p1->next;
            // curr->next = NULL;
        }else {
            // curr = (struct ListNode *)malloc(sizeof(struct ListNode));
            curr->next = p2;
            curr = p2;
            p2 = p2->next;
            // curr->next = NULL;
        }
    }

    return head.next;

}
// @lc code=end

