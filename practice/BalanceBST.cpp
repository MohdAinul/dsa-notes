/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
func balanceBST(root *TreeNode) *TreeNode {
    arr := []int{}

    var inorder func(*TreeNode)
    inorder = func(node *TreeNode) {
        if node == nil {
            return
        }
        inorder(node.Left)
        arr = append(arr, node.Val)
        inorder(node.Right)
    }

    var build func(int, int) *TreeNode
    build = func(left, right int) *TreeNode {
        if left > right {
            return nil
        }

        mid := (left + right) / 2
        node := &TreeNode{Val: arr[mid]}
        node.Left = build(left, mid-1)
        node.Right = build(mid+1, right)

        return node
    }

    inorder(root)
    return build(0, len(arr)-1)
}