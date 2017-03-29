package main

type Player struct {
	version int
}
func (this *Player) Play(file string) {
	switch (this.version) {
	case 2: doPlay2(file)
	default: doPlay1(file)
	}
}

func doPlay1(file string) {
	println("doPlay1(): ", file)
}

func doPlay2(file string) {
	println("doPlay2(): ", file)
}

func main() {
	player := new(Player)

	player.Play("mov.mov")

	player.version = 2
	player.Play("mov.mov")
}
