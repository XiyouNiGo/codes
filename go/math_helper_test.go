package main

import (
	"testing"
)

type calcCase struct{ A, B, Expected int }

func createMulTestCase(t *testing.T, c *calcCase) {
	// 对一些重复的逻辑，标记为帮助函数
	// 这样go test报错不会报在帮助函数内部，而是外部
	t.Helper()
	if res := Mul(c.A, c.B); res != c.Expected {
		t.Fatalf("%d * %d expected %d, but %d got",
			c.A, c.B, c.Expected, res)
	}
}

func MulTest(t *testing.T) {
	createMulTestCase(t, &calcCase{2, 3, 6})
	createMulTestCase(t, &calcCase{2, -3, -6})
	createMulTestCase(t, &calcCase{2, 0, 1})
}