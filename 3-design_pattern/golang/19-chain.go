package main

import "unicode"

type IHandler interface {
	DoHandle(r rune)
}

type Handler struct {
	name string
	//next *Handler
	handler IHandler
}

func (this *Handler) DoHandle(r rune) {
	this.DoHandle(r)
}

type CharHandler struct { Handler }
func (this *CharHandler) DoHandle(r rune) {
	println("Try: CharHandler::DoHandle():", r)
	if unicode.IsLetter(r) {
		println(this.name+" DoHandler():", r);
	} else {
		if this.handler != nil {
			this.handler.DoHandle(r)
		}
	}
}

type NumberHandler struct { Handler }
func (this *NumberHandler) DoHandle(r rune) {
	println("Try: NumberHandler::DoHandle():", r)
	if unicode.IsNumber(r) {
		println(this.name+" DoHandler():", r);
	} else {
		if this.handler != nil {
			this.handler.DoHandle(r)
		}
	}
}

func main() {
	var handler IHandler

	number := &NumberHandler{Handler{name: "NumberHandler"}}
	char := &CharHandler{Handler{name: "CharHandler"}}
	char.handler = number

	handler = char
	
	println("case 'a'")
	handler.DoHandle('a')

	println("\ncase '1'")
	handler.DoHandle('1')
}
