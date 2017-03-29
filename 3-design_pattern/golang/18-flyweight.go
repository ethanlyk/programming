package main

// Flyweight
type Coffee struct {
	flavour string
}

func (this *Coffee) GetCoffee() string {
	return this.flavour
}

// FlyweightFactory
type CoffeeFactory struct {
	coffee map[string]*Coffee
}

func (this *CoffeeFactory) Order(str string) *Coffee {
	if this.coffee == nil {
		this.coffee = make(map[string]*Coffee)
	}

	if val, ok := this.coffee[str]; ok {
		println("\tGot existed:", val.GetCoffee())
		return val
	} 

	println("\tNew coffe:", str)
	this.coffee[str] = &Coffee{str}
	return this.coffee[str]
}

func main() {
	factory := new(CoffeeFactory)

	println("Order Espresso:")
	factory.Order("Espresso")

	println("Order Capucino:")
	factory.Order("Capucino")

	println("Order Espresso:")
	factory.Order("Espresso")

	println("Order Black Coffee:")
	factory.Order("Black Coffee")
}
