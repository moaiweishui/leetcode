- Solution 1: 递归
  - 用一个数组存下当前上限，45%，不加这个条件只有15%
  
- Solution 2: 递归，在S1的基础上，加了一块缓存用来存储计算得到的中间结果，由于限定了整个数组的总和不超过1000，即组合运算符得到的结果范围为-1000~1000，因此设数组列数为2001（没有这个限定条件，估计就得设置动态的缓存了，只存下有效的中间值，用键值对去索引）
  - 75%
