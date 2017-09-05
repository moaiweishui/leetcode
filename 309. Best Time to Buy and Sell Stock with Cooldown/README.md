- Solution 1: 最基本的DP，O(n^2)
  - 10%
- Solution 2: DP，DP的核心在于子状态的表示和转换，S1中用天数（对应价格序列的长度）来表示子状态，
这里进行改进，每一天可以用三种状态表示，buy/sell/rest，buy[i]表示在第i天及之前，以buy状态为末尾的子序列的最大利润，其他同理，
其中rest可以用sell来表示（rest之前必然完成一次sell或者啥都没干，因此rest[i] = sell[i - 1]）
  - 33%
