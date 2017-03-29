package main

// Observer
type User struct {
	name string
}

func (this *User) Update(info string) {
	println("Update "+this.name+": "+info)
}

// Subject
type News struct {
	lstUser []*User
}

func (this *News) Register(o *User) {
	if (this.lstUser == nil) {
		this.lstUser = make([]*User, 0)
	}

	this.lstUser = append(this.lstUser, o)
}

func (this *News) Notify(info string) {
	for _, o := range this.lstUser {
		o.Update(info)
	}
}

func main() {
	news := new(News)

	peter := &User{name: "Peter"}
	news.Register(peter)

	jane := &User{"Jane"}
	news.Register(jane)

	news.Notify("Something happend")
}

