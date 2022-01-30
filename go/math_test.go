package main

import (
	"testing"
)

func AddTest(t *testing.T) {
if res := Add(1, 2); res != 3 {
		t.Errorf("1 + 2 expected be 3, but %d got", res)
	}

	if res := Add(-10, -20); res != -30 {
		t.Errorf("-10 + -20 expected be -30, but %d got", res)
	}
}

func MulTest1(t *testing.T) {
	// 子测试
	t.Run("pos", func(t *testing.T) {
		if Mul(2, 3) != 6 {
			t.Fatal("fail")
		}

	})
	t.Run("neg", func(t *testing.T) {
		if Mul(2, -3) != -6 {
			t.Fatal("fail")
		}
	})
}

func MulTest2(t *testing.T) {
	// table-driven tests
	cases := []struct {
		Name           string
		A, B, Expected int
	}{
		{"pos", 2, 3, 6},
		{"neg", 2, -3, -6},
		{"zero", 2, 0, 0},
	}

	for _, c := range cases {
		t.Run(c.Name, func(t *testing.T) {
			if res := Mul(c.A, c.B); res != c.Expected {
				t.Fatalf("%d * %d expected %d, but %d got",
					c.A, c.B, c.Expected, res)
			}
		})
	}
}