class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        height = {None: 0}
        stack = [(root, False)]
        while stack:
            node, visited = stack.pop()
            if visited:
                lh, rh = height[node.left], height[node.right]
                if abs(lh - rh) > 1:
                    return False
                height[node] = 1 + max(lh, rh)
            else:
                stack.append((node, True))
                if node.right:
                    stack.append((node.right, False))
                if node.left:
                    stack.append((node.left, False))
        return True