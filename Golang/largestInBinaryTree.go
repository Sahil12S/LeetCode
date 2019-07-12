package main

//
// Binary trees are already defined with this interface:
// type Tree struct {
//   Value interface{}
//   Left *Tree
//   Right *Tree
// }
func largestValuesInTreeRows(t *Tree) []int {
	if t == nil {
		return []int{}
	}

	var result []int

	q := []*Tree{t}

	for len(q) > 0 {
		l := len(q)
		result = append(result, -1001)
		for l > 0 {
			curr := q[0]
			q = q[1:]
			result[len(result)-1] = max(result[len(result)-1], curr.Value.(int))
			if curr.Left != nil {
				q = append(q, curr.Left)
			}
			if curr.Right != nil {
				q = append(q, curr.Right)
			}
			l--
		}
	}
	return result
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
