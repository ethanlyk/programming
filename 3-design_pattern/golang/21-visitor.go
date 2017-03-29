package main

// Element::accept()
type ICarElement interface {
	accept(v *CarElementVisitor)
}
type CarElement struct {
	name string
}
func (this *CarElement) accept(v *CarElementVisitor) {
	this.accept(v)
}

type Wheel struct {
	CarElement
}
/*
func (this *Wheel) accept(v *CarElementVisitor) {
	v.visit(this)
}
*/

type Car struct {
	elements []*CarElement
}
func (this *Car) accept(v *CarElementVisitor) {
	for _, elm := range this.elements {
		elm.accept(v)
	}
	v.visit(this)
}

// Visitor::visit()
type ICarElementVisitor interface {
	visit(w *Wheel)
	visit(c *Car)
}

type CarElementVisitor struct {}
func (this *CarElementVisitor) visit(w *Wheel) {
	this.visit(w)
}

func (this *CarElementVisitor) visit(c *Car) {
	this.visit(c)
}

type PrintVisitor struct {
	CarElementVisitor
}
func (this *PrintVisitor) visit(w *Wheel) {
	println("PrintVisitor::visit: "+w.name+" wheel")
}

func (this *PrintVisitor) visit(c *Car) {
	println("PrintVisitor::visit: car")
}
/****/
func main() {
	var elm ICarElement
	car := new(Car)
	car.elements = make([]*CarElement)

	fw := &Whell{"front"}
	elm = fw
	append(car.elements, elm)
}
