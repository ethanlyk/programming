package main

type IMove interface {
	move()
}

type StrategyA struct {}
func (this *StrategyA) move() {
	println("Move on StrategyA")
}

type StrategyB struct {}
func (this *StrategyB) move() {
	println("Move on StrategyB")
}

type Chess struct {}
func (this *Chess) Next(o IMove) {
	o.move()
}

func main() {
	chess := new(Chess)

	var s IMove
	sa := new(StrategyA)
	s = sa
	chess.Next(s)

	sb := new(StrategyB)
	s = sb
	chess.Next(s)
}
