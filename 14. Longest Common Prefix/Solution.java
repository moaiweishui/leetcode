class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";
        StringBuilder sb = new StringBuilder();

        int index = 0;
        while(isValidIndex(index, strs)) {
            if(isSameChar(index, strs)){
                sb.append(strs[0].charAt(index));
                index++;
            } else {
              break;
            }
        }
        return sb.toString();
    }

    private boolean isValidIndex(int index, String[] strs) {
        for (String str : strs) {
            if (index >= str.length()) {
                return false;
            }
        }
        return true;
    }

    private boolean isSameChar(int index, String[] strs) {
        char c = strs[0].charAt(index);
        for(int i = 1; i < strs.length; i++) {
            if(strs[i].charAt(index) != c){
                return false;
            }
        }
        return true;
    }
}
