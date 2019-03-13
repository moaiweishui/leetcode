class Solution {
    public int reverse(int x) {
        if(x == 0) return x;
        boolean neg = x < 0;
        long input = (long) x;
        long output = 0;
        if (neg) input = -input;
        while(input != 0) {
            output = output * 10;
            output += input % 10;
            input = input / 10;
        }

        if(neg) output = -output;

        int res;
        try {
            res = Math.toIntExact(output);
        } catch (ArithmeticException e) {
            res = 0;
        }
        return res;
    }
    
}
