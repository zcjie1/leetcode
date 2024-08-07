/*
 * @lc app=leetcode.cn id=1137 lang=c
 *
 * [1137] 第 N 个泰波那契数
 *
 * https://leetcode.cn/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (61.00%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    212.8K
 * Total Submissions: 348.8K
 * Testcase Example:  '4'
 *
 * 泰波那契序列 Tn 定义如下： 
 * 
 * T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
 * 
 * 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 4
 * 输出：4
 * 解释：
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 25
 * 输出：1389537
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 37
 * 答案保证是一个 32 位整数，即 answer <= 2^31 - 1。
 * 
 * 
 */

// @lc code=start

typedef struct Matrix {
    long mat[3][3];
}Matrix;

Matrix multiply(Matrix *a, Matrix *b) {
    struct Matrix c;
    long c00, c11, c22;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c00 = a->mat[i][0] * b->mat[0][j];
            c11 = a->mat[i][1] * b->mat[1][j];
            c22 = a->mat[i][2] * b->mat[2][j];
            c.mat[i][j] = c00 + c11 + c22;
        }
    }
    return c;
}

Matrix qpow(Matrix *a, int n) {
    Matrix ret = {{
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
    }};
    while(n > 0) {
        if(n & 1)
            ret = multiply(&ret, a);
        n = n >> 1;
        *a = multiply(a, a);
    }
    return ret;
}


int tribonacci(int n){
    if(n < 1)
        return 0;
    Matrix m = {{
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    }};

    Matrix ret = qpow(&m, n);
    return ret.mat[2][0] + ret.mat[2][1];
}
// @lc code=end

