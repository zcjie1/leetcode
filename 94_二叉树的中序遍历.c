/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (77.12%)
 * Likes:    2129
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;

    struct TreeNode *stk[101];
    int top = 0;
    
    struct TreeNode *curr = root;

    while(curr || top > 0) {
        while(top > 0 && !curr) {
            curr = stk[--top];
            ans[(*returnSize)++] = curr->val;
            curr = curr->right;
        }

        if(!curr)
            break;

        stk[top++] = curr;
        curr = curr->left;

    }

    return ans;

}
// @lc code=end

