class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> vmap = new HashMap<>();
        vmap.put('M', 1000);
        vmap.put('D', 500);
        vmap.put('C', 100);
        vmap.put('L', 50);
        vmap.put('X', 10);
        vmap.put('V', 5);
        vmap.put('I', 1);

        int num = 0;
        char last = s.charAt(0);
        num += vmap.get(last);
        for(int i = 1; i < s.length(); i++) {
            if(vmap.get(s.charAt(i)) > vmap.get(last)) {
                num = num - 2 * vmap.get(last) + vmap.get(s.charAt(i));
            } else {
                num += vmap.get(s.charAt(i));
            }
            last = s.charAt(i);
        }
        return num;
    }
}
