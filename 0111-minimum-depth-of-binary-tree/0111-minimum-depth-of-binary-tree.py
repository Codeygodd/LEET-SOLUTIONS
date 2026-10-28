class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        depth = 0
        level = [root]
        while level:
            depth += 1
            for n in level:
                if not n.left and not n.right:
                    return depth
            level = [c for n in level for c in (n.left, n.right) if c]
        return depth