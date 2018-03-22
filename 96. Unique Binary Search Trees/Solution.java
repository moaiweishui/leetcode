class Solution {
    public int numTrees(int n) {
        
        int[] mem = new int[n + 1];
        mem[0] = 1;
        mem[1] = 1;
        for(int end = 2; end <= n; end++){
            for(int root = 1; root <= end; root++){
                mem[end] += mem[root - 1] * mem[end - root];
            }
        }

        return mem[n];
    }
}
