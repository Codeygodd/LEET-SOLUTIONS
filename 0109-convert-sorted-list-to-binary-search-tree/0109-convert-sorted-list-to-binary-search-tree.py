class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next

        def helper(lo, hi):
            if lo > hi:
                return None
            mid = (lo + hi) // 2
            return TreeNode(vals[mid], helper(lo, mid - 1), helper(mid + 1, hi))

        return helper(0, len(vals) - 1)