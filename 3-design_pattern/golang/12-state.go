package main

const (
	Normal = iota
	Gold = 1000

	NormalRate = 0.2
	GoldRate = 0.5
)

type IState interface {
	Deposite(val int)
	Withdraw(val int) int 
	Rate() float32
}

type Account struct {
	money int
	rate float32
	state int
}

func (this *Account) Deposite(val int) {
	this.money += val
	this.rate = NormalRate
	if (this.money >= Gold) {
		this.state = Gold
		this.rate = GoldRate
	}
}

func (this *Account) Withdraw(val int) int {
	if (this.money - val >= 0) {
		this.money -= val
	}

	if (this.money < Gold) {
		this.state = Normal
	}

	return this.money
}

func (this *Account) Rate() float32 {
	switch (this.state) {
	case Gold:
		this.rate = GoldRate

	case Normal:
		fallthrough
	default:
		this.rate = NormalRate
	}

	return this.rate
}

func main() {
	act := new(Account)
	act.Deposite(600)
	println("account:", act.money, ", rate:", act.Rate())

	act.Deposite(500)
	println("account:", act.money, ", rate:", act.Rate())

	act.Withdraw(200)
	println("account:", act.money, ", rate:", act.Rate())
}
