package main

// Adaptee
type Object struct{}
func (this *Object) Do() {
	println("Object::Do()")
}

// Adapter
type Wrapper struct {
	o Object
}

func (this *Wrapper) Do() {
	this.o.Do()
}

/////
func main() {
	w := new(Wrapper)
	w.Do()
}
