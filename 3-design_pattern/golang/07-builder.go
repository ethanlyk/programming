package main

type Tea struct {
	name string
}
func (this *Tea) Info() string {
	return this.name
}

type TeaStore struct {}
func (this *TeaStore) OrderBubbleBlackTea() *Tea {
	println("OrderBubbleBlackTea(): ")
	tea := new(Tea)
	this.getTea("BlackTea", tea)
	this.addBubble(tea)
	this.brew(tea)
	this.pourCup(tea)

	return tea
}

func (this *TeaStore) getTea(tea string, pTea *Tea) {
	println("getTea()")
	pTea.name = tea
}

func (this *TeaStore) addBubble(pTea *Tea) {
	println("addBubble()")
	pTea.name = pTea.name + "+Bubble"
}

func (this *TeaStore) brew(pTea *Tea) {
	println("brew()")
}

func (this *TeaStore) pourCup(pTea *Tea) {
	println("pureCup()")
}

func main() {
	builder := new(TeaStore)
	tea := builder.OrderBubbleBlackTea()
	println("\nGot: ", tea.Info())
}
