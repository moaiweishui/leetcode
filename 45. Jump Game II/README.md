- BFS的思想，相同步数内能到达的点视为一层，实际实现用了三个指针
  - i指向数组中当前的点
  - curr_max指向当前步数下最远能到达的点的index
  - last_max指向上一层所能到达的最远点的index
