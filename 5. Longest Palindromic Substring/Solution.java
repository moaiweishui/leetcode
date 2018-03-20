class Solution {
    public String longestPalindrome(String s) {
        int maxLength = 0;
        int start = 0, end = 0;

        for(int i = 0; i < s.length(); i++){
            int lenOdd = expend(s, i, true);
            int lenEven = expend(s, i, false);
            int len = Math.max(lenOdd, lenEven);
            if(len > maxLength){
                maxLength = len;
                if(len % 2 == 0){
                    start = i - len / 2 + 1;
                }else{
                    start = i - len / 2;
                }
                
                end = len + start - 1;
            }
        }
        
        return s.substring(start, end + 1);
    }
    
    // 中心点
    public static int expend(String s, int index, boolean odd){
        int l = index;
        int r = index + (odd ? 0 : 1);
        while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)){
            l--;
            r++;
        }
        return r - l - 1;
    }
}
