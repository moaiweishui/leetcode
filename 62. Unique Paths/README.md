- Solution 1: 排列组合,m行n列，则需要向下移动m-1次，向右移动n-1次
  - 超时
- Solution 2: 动态规划，F(m, n) = F(m-1, n) + F(m, n - 1)
  - 38%