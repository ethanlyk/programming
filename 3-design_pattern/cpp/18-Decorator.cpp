#include <stdio.h>

#include <string>

using namespace std;

class UIComponent {
public:
	void Set(int iX, int iY) {
		m_iX = iX;
		m_iY = iY;
	}

	virtual void Draw() = 0;

private:
	int m_iX, m_iY;
};

class Image : public UIComponent {
public:
	Image(string strSource) {
		m_strSource = strSource;
	}

	void Draw() {
		printf("Image::Draw():%s\n", m_strSource.c_str());
	}

private:
	string m_strSource;
};

class Button : public UIComponent {
public:
	Button(Image& img):m_image(img) {}

	void Draw() {
		printf("Button::Draw()\n");
	}

	void Click() {
		printf("Button::Click()\n");
	}

private:
	Image& m_image;
};

int main() {
	Image img("myjpg.jpg");
	img.Draw();

	Button btn(img);
	btn.Click();
}
