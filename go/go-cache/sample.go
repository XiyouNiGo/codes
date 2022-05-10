package main

import (
	"fmt"
	"time"

	"github.com/patrickmn/go-cache"
)

func main() {
	// Create a cache with a default expiration time of 5 minutes, and which
	// purges expired items every 10 minutes
	c := cache.New(5*time.Minute, 10*time.Minute)

	{
		c.Set("foo", "bar", cache.DefaultExpiration)

		c.Set("baz", 42, cache.NoExpiration)

		foo, found := c.Get("foo")
		if found {
			fmt.Println(foo)
		}
	}

	// type assertion is needed
	{
		foo, found := c.Get("foo")
		if found {
			fmt.Println(foo.(string))
		}
	}

	// Want performance? Store pointers!
	{
		type MyStruct struct {
			Test string
		}
		ms := MyStruct{"test"}
		c.Set("foo", &ms, cache.DefaultExpiration)
		if x, found := c.Get("foo"); found {
			foo := x.(*MyStruct)
			fmt.Println(foo.Test)
		}
	}
}
