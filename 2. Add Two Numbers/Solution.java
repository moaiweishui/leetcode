class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode root = new ListNode(-1);
        ListNode curr = root;
        int c = 0;
        int sum = 0;
        int v1, v2;
        while (l1 != null || l2 != null) {
            v1 = l1 == null ? 0 : l1.val;
            v2 = l2 == null ? 0 : l2.val;
            sum = v1 + v2 + c;
            c = sum >= 10 ? 1 : 0;
            sum = sum % 10;
            curr.next = new ListNode(sum);
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
            curr = curr.next;
        }
        if(c != 0) {
            curr.next = new ListNode(c);
        }
        return root.next;
    }
}
