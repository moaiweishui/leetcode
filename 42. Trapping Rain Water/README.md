- Solution 1: Brute force
  - 3%
  
- Solution 2: 双指针分别依次从左与从右边向中间遍历，碰到低的，存水，碰到高的，更新高度
  - 60%

- Solution 3: 用数组分别存下每个节点左右两侧的最大高度,再用一次循环，得到每个节点能存储的水量
  - 对整个数组做了三次完整的循环，时间复杂度O(n)， 29%
  
- Solution 4: 用stack来存index，遍历数组，将下标push进stack，在这个过程中，遇到当前值大于栈顶值的，就将从栈顶开始的比当前值小的都pop出来，每pop一个，就计算该index被围起来所能存储的水量
  - 整体只需循环一次，但是循环体内部含有额外的循环操作（pop），因此比Solution3要慢，18%

- Solution 5: 在Solution2的基础上修改，S2是左右交替遍历，S5是先从左往右遍历一遍，记录下从左往右看时每个节点能存储下的水量（部分有效），同时记下最大值出现的位置，下一次循环时，从右往左遍历至最大值所在位置，更新这部分节点所能存储的水量。
  - 94%
