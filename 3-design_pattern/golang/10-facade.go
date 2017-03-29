package main

import "math"

type Calculator struct {}

func (this *Calculator) Add(a, b int) int {
	return a+b
}

func (this *Calculator) Sqrt(f float64) float64 {
	return math.Sqrt(f)
}

func (this *Calculator) Log(f float64) float64 {
	return math.Log2(f)
}

func main() {
	c := new(Calculator)

	println("Do add(3, 4): ", c.Add(3, 4))
	println("Do Squrt(4): ", c.Sqrt(4))
	println("Do Log(3): ", c.Log(3))
}
