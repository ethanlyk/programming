package main

import (
	"math"
)

// base
type IShape interface {
	Position() (x, y int)
	Name() string
	Area() float32
}
type Shape struct {
	x, y int
	name string
}

func (this *Shape) Position() (x, y int) {
	return this.x, this.y
}

func (this *Shape) Name() string {
	return this.name
}

// inheritance-1
type Rectangle struct {
	Shape
	w, h int
}

func (this *Rectangle) Area() float32 {
	return float32(this.w * this.h)
}

// inheritance-2
type Circle struct {
	Shape
	r int
}

func (this *Circle) Area() float32 {
	f := float32(this.r)
	return f*f*math.Pi
}

func main() {
	var shape IShape

	r := &Rectangle{Shape{5, 5, "Rectangle"}, 3, 4}
	shape = r

	iX, iY := shape.Position()
	println(shape.Name(), "@(", iX, iY, ") area:", shape.Area())

	c := &Circle{Shape{10, 10, "Circle"}, 9}
	shape = c

	iX, iY = shape.Position()
	println(shape.Name(), "@(", iX, iY, ") area:", shape.Area())
}
