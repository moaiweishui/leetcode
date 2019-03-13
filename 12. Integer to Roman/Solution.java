class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < num / 1000; i++) {
            sb.append("M");
        }
        num = num % 1000;

        // count of 100
        int cnt = num / 100;
        if(cnt == 9) {
            sb.append("CM");
        } else if(cnt == 4) {
            sb.append("CD");
        } else {
            if(cnt >= 5) {
                sb.append("D");
                cnt = cnt - 5;
            }
            while(cnt > 0) {
                sb.append("C");
                cnt--;
            }
        }

        num = num % 100;

        // count of 10
        cnt = num / 10;
        if(cnt == 9) {
            sb.append("XC");
        } else if(cnt == 4) {
            sb.append("XL");
        } else {
            if(cnt >= 5) {
                sb.append("L");
                cnt = cnt - 5;
            }
            while(cnt > 0) {
                sb.append("X");
                cnt--;
            }
        }

        num = num % 10;
        // count of 1
        cnt = num;
        if(cnt == 9) {
            sb.append("IX");
        } else if(cnt == 4) {
            sb.append("IV");
        } else {
            if(cnt >= 5) {
                sb.append("V");
                cnt = cnt - 5;
            }
            while(cnt > 0) {
                sb.append("I");
                cnt--;
            }
        }
        
        return sb.toString();
    }
}
