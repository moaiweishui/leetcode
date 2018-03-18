class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];

        HashMap<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(hashMap.containsKey(target - nums[i])){
                res[0] = hashMap.get(target - nums[i]);
                res[1] = i;
                break;
            }else{
                hashMap.put(nums[i], i);
            }
        }

        return res;
    }
}
