class Solution {
    public String convert(String s, int numRows) {
        if(s.isEmpty() || numRows == 1){
            return s;
        }
        StringBuilder res = new StringBuilder();
        int remain = s.length() % (2 * numRows - 2);
        int maxCols = s.length() / (2 * numRows - 2) * (numRows - 1);
        if(remain > 0) {
            maxCols += remain <= numRows ? 1 : remain - numRows + 1;
        }
        int index;
        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < maxCols; col++) {
                int cnt = col / (numRows - 1);
                if(res.length() == s.length()){
                    break;
                }
                if(col % (numRows - 1) == 0){
                    index = cnt * 2 * (numRows - 1) + row;
                    if(index < s.length()){
                        res.append(s.charAt(index));
                    }
                } else {
                  int interval = col % (numRows - 1);
                  if(numRows - 1 - row == interval){
                      res.append(s.charAt(cnt * 2 * (numRows - 1) + numRows + interval - 1));
                  }
                }
            }
        }

        return res.toString();
    }
}
