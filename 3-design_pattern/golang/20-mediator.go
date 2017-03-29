package main

// Colleague
type Client struct {
	name string
	chatroom *Chatroom
}

func (this *Client) Attach(chatroom *Chatroom) {
	this.chatroom = chatroom
}

func (this *Client) Talk(user *Client, msg string) {
	this.chatroom.Talk(this, user, msg)
}

// Mediator
type Chatroom struct {
	user map[string]*Client
}

func (this *Chatroom) Join(user *Client) {
	if this.user == nil {
		this.user = make(map[string]*Client)
	}

	if _, ok := this.user[user.name]; !ok {
		this.user[user.name] = user
		user.Attach(this)
	}

	println(user.name+" joins the chatroom")
}

func (this *Chatroom) Talk(from , to *Client, msg string) {
	if _, ok1 := this.user[from.name]; !ok1 {
		println(from.name+" does not join the room")
	}

	if _, ok2 := this.user[to.name]; !ok2 {
		println(to.name+" does not join the room")
	}
	
	println(from.name+" talks to "+to.name+": "+msg)
}

// main
func main() {
	chatroom := new(Chatroom)

	c1 := &Client{name: "Rose"}
	chatroom.Join(c1)

	c2 := &Client{name: "Jack"}
	chatroom.Join(c2)

	c1.Talk(c2, "Hello")
}
