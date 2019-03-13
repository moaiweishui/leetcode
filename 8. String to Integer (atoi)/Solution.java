class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length() == 0) return 0;
        int startIndex = 0;
        while(startIndex < str.length() && str.charAt(startIndex) == ' ') {
            startIndex++;
        }
        int endIndex = 0;
        if(startIndex >= str.length()) {
            return 0;
        } else if(str.charAt(startIndex) == '-' || str.charAt(startIndex) == '+') {
            endIndex = startIndex + 1;
            while(endIndex < str.length() && '0' <= str.charAt(endIndex) && str.charAt(endIndex) <= '9') {
                endIndex++;
            }
            if(endIndex == startIndex + 1) return 0;
        } else if ('0' <= str.charAt(startIndex) && str.charAt(startIndex) <= '9') {
            endIndex = startIndex;
            while(endIndex < str.length() && '0' <= str.charAt(endIndex) && str.charAt(endIndex) <= '9') {
                endIndex++;
            }
        } else {
            return 0;
        }
        String numberStr = removeLeadingZero(str.substring(startIndex, endIndex));
        boolean negFlag = numberStr.charAt(0) == '-';
        if(numberStr.length() > 11) return negFlag ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int res;
        try {
            res = Math.toIntExact(Long.valueOf(numberStr));
        } catch (ArithmeticException e) {
            res = negFlag ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
        return res;
    }
    
    private String removeLeadingZero(String s) {
        int start = 0;
        String prefix = s.charAt(0) == '-' ? "-" : "";
        if(s.charAt(0) == '-' || s.charAt(0) == '+') start = 1;

        while(start < s.length() && s.charAt(start) == '0') {
            start++;
        }
        return prefix + (start == s.length() ? "0" : s.substring(start));
    }
}
