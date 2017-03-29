package main

type Object struct {
	name string
}

var obj *Object
func ObjectInstance() *Object {
	if (obj == nil) {
		obj = new(Object)
	}
	return obj
}

func main() {
	o := ObjectInstance()
	o.name = "MyInstance"
	println("o:", o.name, o)

	o = ObjectInstance()
	println("o:", o.name, o)
}
