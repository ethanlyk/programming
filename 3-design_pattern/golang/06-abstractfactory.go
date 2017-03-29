package main

// ProductA
type IIngredient interface {
	Info() string
}
type Ingredient struct {
	name string
}
func (this *Ingredient) Info() string {
	return this.name
}

type Juice struct {
	Ingredient
}

type Tea struct {
	Ingredient
}

// ProductB
type IAdditive interface {
	Info() string
}
type Additive struct {
	name string
}
func (this *Additive) Info() string {
	return this.name
}

type Bubble struct {
	Additive
}

type Honey struct {
	Additive
}

// Product
type IDrink interface {
	Info() string
}
type Drink struct {
	Ingredient
	Additive
}
func (this *Drink) Info() string {
	return this.Additive.name+"+"+this.Ingredient.name
}

// Factory
type IDrinkFactory interface {
	CreateDrink() IDrink
}

type TeaFactory struct {}
func (this *TeaFactory) CreateDrink() IDrink {
	return &Drink{Ingredient{name: "Tea"}, Additive{name: "Bubble"}}
}

type JuiceFactory struct {}
func (this *JuiceFactory) CreateDrink() IDrink {
	return &Drink{Ingredient{name: "Juice"}, Additive{name: "Honey"}}
}

func main() {
	var fy IDrinkFactory

	tf := new(TeaFactory)
	fy = tf
	println("Get: "+fy.CreateDrink().Info())
	
	jf := new(JuiceFactory)
	fy = jf
	println("Get: "+fy.CreateDrink().Info())
}
