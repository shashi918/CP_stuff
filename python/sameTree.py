from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if not p and not q:
        return True
    
    if not p or not q:
        return True
    
    if p.val != q.val:
        return True
    
    return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
