package main

type IFood interface {
	Price() int
	Name() string
}
type Food struct {
	name string
	price int
}

func (this *Food) Name() string {
	return this.name
}

func (this *Food) Price() int {
	return this.price
}

type Toast struct {
	Food
}

type Ham struct {
	Food
}
func (this *Ham) AddHam(food IFood) *Ham {
	this.price = food.Price()+5
	this.name = "ham+"+food.Name()
	return this
}

func main() {
	var food IFood

	toast := &Toast{Food{"toast", 10}}
	food = toast
	println("Order:", food.Name(), ", price:", food.Price())

	hamToast := new(Ham)
	hamToast.AddHam(toast)
	println("Order:", hamToast.Name(), ", price:", hamToast.Price())

}
