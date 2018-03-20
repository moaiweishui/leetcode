class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        int maxLength = 0;
        int startIndex = 0;
        for(int i = 0; i < s.length(); i++){
            Character c = s.charAt(i);
            // startIndex是以当前字符为子串结尾时，最远的起点
            if(hashMap.containsKey(c)){
                //当前字符上一个出现位置
                int lastIndex = hashMap.get(c);
                startIndex = Math.max(lastIndex + 1, startIndex);
            }

            maxLength = Math.max(maxLength, i - startIndex + 1);
            hashMap.put(c, i);
        }

        return maxLength;
    }
}

/**************************** Solution 2 ********************************/
// 86.38%
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;

        //用来记录字符出现的位置
        int[] pos = new int[128];
        // 从1开始
        int start = 1;
        
        for(int i = 0; i < s.length(); i++){
            if(pos[s.charAt(i)] != 0){
                //该字符在之前出现过
                if(pos[s.charAt(i)] >= start){
                    start = pos[s.charAt(i)] + 1;
                }
            }
            maxLength = Math.max(i + 1 - start + 1, maxLength);
            pos[s.charAt(i)] = i + 1;
        }

        return maxLength;
    }
}
