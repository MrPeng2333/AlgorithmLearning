/*
 * @lc app=leetcode.cn id=1161 lang=golang
 *
 * [1161] 最大层内元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 // 10000个节点的二叉树不超过14层
func maxLevelSum(root *TreeNode, level int, res *int, levelSum *[]int) {
	if root == nil {
		return
	}
	levelSum[level] += root.Val
	if levelSum[level] > levelSum[res] {
		res = level
	} else if levelSum[level] == levelSum[res] && level < res{
		res = level
	}
	maxLevelSum(root.Left, level + 1, res, levelSum)
	maxLevelSum(root.Right, level + 1, res, levelSum)

}
func maxLevelSum(root *TreeNode) int {
	levelSum := make([]int, 15)
	res := 16
	maxLevelSum(root, 1, &res, &levelSum)
	return res
}
// @lc code=end

