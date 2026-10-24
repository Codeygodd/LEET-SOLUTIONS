class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lo, hi = ListNode(), ListNode()
        l, h = lo, hi
        while head:
            if head.val < x:
                l.next = head
                l = l.next
            else:
                h.next = head
                h = h.next
            head = head.next
        h.next = None
        l.next = hi.next
        return lo.next
        