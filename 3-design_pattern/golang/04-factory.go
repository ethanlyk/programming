package main

// Product
type Tea struct {
	name string
}
type ITea interface {
	Info() string
}

type GreenTea struct {
	Tea
}
func (this *GreenTea) Info() string {
	return this.name
}

type BlackTea struct {
	Tea
}
func (this *BlackTea) Info() string {
	return this.name
}

// Factory
type ITeaFactory interface {
	CreateTea() ITea
}

type GreenTeaFactory struct {}
func (this *GreenTeaFactory) CreateTea() ITea {
	return &GreenTea{Tea{name: "Green tea"}}
}

type BlackTeaFactory struct {}
func (this *BlackTeaFactory) CreateTea() ITea {
	return &BlackTea{Tea{name: "Black tea"}}
}

func main() {
	var factory ITeaFactory

	gf := new(GreenTeaFactory)
	factory = gf
	println("Get: "+factory.CreateTea().Info())
	
	bf := new(BlackTeaFactory)
	factory = bf
	println("Get: "+factory.CreateTea().Info())
}
