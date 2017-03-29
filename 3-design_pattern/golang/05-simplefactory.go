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
type SimpleTeaFactory struct {}
func (this *SimpleTeaFactory) CreateTea(tea string) ITea {
	if (tea == "green")	{
		return &GreenTea{Tea{name: "Green tea"}}
	} else if (tea == "black") {
		return &BlackTea{Tea{name: "Black tea"}}
	}

	return nil
}

func main() {
	fy := new (SimpleTeaFactory)
	println("Get: "+fy.CreateTea("green").Info())
	
	println("Get: "+fy.CreateTea("black").Info())
}
