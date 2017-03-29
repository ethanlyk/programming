package main

type IComponent interface {
	Add(comp IComponent)
	Info() 
	setName(parent string)
}

type Base struct {
	name string
}

// Composite
type Folder struct {
	Base
	ayChild []IComponent
}

func (this *Folder) Add(p IComponent) {
	if (this.ayChild == nil) {
		this.ayChild = make([]IComponent, 0)
	}
	this.ayChild = append(this.ayChild, p)
	p.setName(this.name)
}

func (this *Folder) setName(parent string) {
	if (parent == "/") {
		this.name = parent + this.name
	} else {
		this.name = parent + "/" + this.name
	}
}

func (this *Folder) Info() {
	println(this.name)

	if (this.ayChild != nil) {
		for _, elm := range this.ayChild {
			elm.Info()
		}
	}
}

// Leaf
type File struct {
	Base
}

func (this *File) Add(comp IComponent) {
	return
}

func (this *File) Info() {
	println(this.name)
}

func (this *File) setName(parent string) {
	if (parent == "/") {
		this.name = parent + this.name
	} else {
		this.name = parent + "/" + this.name
	}
}

// main
func main() {
	var comp IComponent

	root := &Folder{Base{name: "/"}, nil}

	etc := &Folder{Base{name: "etc"}, nil}
	comp = etc
	root.Add(comp)

	conf := &File{Base{name: "test.conf"}}
	comp = conf
	etc.Add(conf)

	init := &File{Base{name: "init.rc"}}
	comp = init
	root.Add(init)

	root.Info();
}
