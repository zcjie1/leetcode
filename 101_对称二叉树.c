/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (60.82%)
 * Likes:    2781
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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

bool isSymTree(struct TreeNode* p, struct TreeNode* q) {
    bool curr, left, right;

    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    
    if(p->val != q->val)
        return false;
    
    left = isSymTree(p->left, q->right);
    if(!left)
        return false;
    
    right = isSymTree(p->right, q->left);
    if(!right)
        return false;
    
    return true;
    
}

bool isSymmetric(struct TreeNode* root) {
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->left == NULL || root->right == NULL)
        return false;
    
    if(isSymTree(root->left, root->right))
        return true;
    else
        return false;
}
// @lc code=end

