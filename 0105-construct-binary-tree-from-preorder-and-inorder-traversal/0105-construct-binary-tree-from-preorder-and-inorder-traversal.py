class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        stack = [root]
        j = 0
        for i in range(1, len(preorder)):
            node = stack[-1]
            if node.val != inorder[j]:
                node.left = TreeNode(preorder[i])
                stack.append(node.left)
            else:
                while stack and stack[-1].val == inorder[j]:
                    node = stack.pop()
                    j += 1
                node.right = TreeNode(preorder[i])
                stack.append(node.right)
        return root