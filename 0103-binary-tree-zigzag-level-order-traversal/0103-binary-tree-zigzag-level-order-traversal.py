class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        level = [root] if root else []
        left_to_right = True
        while level:
            vals = [n.val for n in level]
            res.append(vals if left_to_right else vals[::-1])
            left_to_right = not left_to_right
            level = [c for n in level for c in (n.left, n.right) if c]
        return res