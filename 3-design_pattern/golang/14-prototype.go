package main

type IClone interface {
	clone(obj IClone) IClone
}

type Font struct {
	name string
	size int
}

func (this *Font) clone() Font {
	font := new(Font)
	font.name = this.name
	font.size = this.size

	return *font
}

type ColorFont struct {
	font Font
	color string
}

type FontCache struct {
	fontmap map[string]*Font
}

func (this *FontCache) Put(font *Font) {
	if this.fontmap == nil {
		this.fontmap = make(map[string]*Font)
	}

	if _, ok := this.fontmap[font.name]; !ok {
		this.fontmap[font.name] = font
	}
}

func (this *FontCache) Get(str string) Font {
	if this.fontmap != nil {
		if val, ok := this.fontmap[str]; ok {
			return val.clone()
		}
	}

	return Font{}
}

func main() {
	fontcache := new(FontCache)

	fa := &Font{"FontA", 10}
	fontcache.Put(fa)

	fb := &Font{"FontB", 20}
	fontcache.Put(fb)

	cf := new(ColorFont)
	cf.font = fontcache.Get("FontA")
	cf.color = "red"
	println("color font: ", cf.font.name, cf.font.size, cf.color)
}

