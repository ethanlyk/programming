package main

type IDisplay interface {
	Display()
}

// RealSubject
type ProxyImage struct {
	file string
}
func (this *ProxyImage) Display() {
	println("Display:", this.file)
}

func (this *ProxyImage) Load() {
	println("Load:", this.file)
}

// Proxy
type Image struct {
	image *ProxyImage
	file string
}

func (this *Image) Display() {
	if this.image == nil {
		this.image = &ProxyImage{this.file}
		this.image.Load()
	}
	this.image.Display()
}

// main
func main() {
	image := &Image{file: "myimage.jpg"}
	image.Display()
	image.Display()
}
