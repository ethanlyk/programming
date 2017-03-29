package main

import (
	"fmt"
	"path"
)

// Command
type ICommand interface {
	Execute(file string) bool
}

// Music player
type Music struct {
	file string
}

func (this *Music) Execute(file string) bool {
	if (path.Ext(file) == ".mp3") {
		fmt.Println("Music play: "+file)
		return true
	}

	return false
}

// Movie player
type Movie struct {
	file string
}

func (this *Movie) Execute(file string) bool {
	if (path.Ext(file) == ".avi") {
		fmt.Println("Movie play: "+file)
		return true
	}

	return false
}

// Invoker
type Player struct {
	lstCommand []ICommand
}

func (this *Player) Register(l ICommand) {
	if this.lstCommand == nil {
		this.lstCommand = make([]ICommand, 0)
	}

	this.lstCommand = append(this.lstCommand, l)
}

func (this *Player) Play(file string) {
	for _, l := range this.lstCommand {
		//fmt.Printf("%d: 0x%p \n", i, l)
		if l.Execute(file) {
			return
		}
	}
}


func main() {
	var p ICommand

	player := new(Player)

	music := new(Music)
	p = music
	player.Register(p)

	movie := new(Movie)
	p = movie
	player.Register(p)

	player.Play("mymovie.avi")
	player.Play("mymusic.mp3")
}

