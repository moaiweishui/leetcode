class Solution {
    public static final Map<Character, List<Character>> HMAP = new HashMap<Character, List<Character>>(){{
        put('2', Arrays.asList('a', 'b', 'c'));
        put('3', Arrays.asList('d', 'e', 'f'));
        put('4', Arrays.asList('g', 'h', 'i'));
        put('5', Arrays.asList('j', 'k', 'l'));
        put('6', Arrays.asList('m', 'n', 'o'));
        put('7', Arrays.asList('p', 'q', 'r', 's'));
        put('8', Arrays.asList('t', 'u', 'v'));
        put('9', Arrays.asList('w', 'x', 'y', 'z'));
    }};

    private void DFS(String digits, Integer index, String mem, List<String> res) {
        if(index >= digits.length()) {
            res.add(mem);
            return;
        }
        List<Character> candidates = HMAP.get(digits.charAt(index));
        for (Character candidate : candidates) {
            mem = mem + candidate;
            DFS(digits, index + 1, mem, res);
            mem = mem.substring(0, mem.length() - 1);
        }
    }
    
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if(digits == null || digits.length() == 0) return res;

        String mem = "";
        DFS(digits, 0, mem, res);
        return res;
    }
}
