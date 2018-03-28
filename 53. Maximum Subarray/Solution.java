class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 1) return nums[0];

        int[] mem = new int[nums.length];
        mem[0] = nums[0];
        int max = mem[0];
        for(int i = 1; i < nums.length; i++){
            if(mem[i - 1] < 0){
                mem[i] = nums[i];
            }else{
                mem[i] = mem[i - 1] + nums[i];
            }
            if(mem[i] > max) max = mem[i];
        }

        return max;
    }
}
