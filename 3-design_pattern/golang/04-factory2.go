package main

// Product
type ITea interface {
	Info() string
}
type Tea struct {
	name string
}
func (this *Tea) Info() string {
	return this.name
}

type GreenTea struct {
	Tea
}

type BlackTea struct {
	Tea
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
