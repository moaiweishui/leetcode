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
