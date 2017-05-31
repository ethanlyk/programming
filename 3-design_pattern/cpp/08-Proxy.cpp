#include <stdio.h>
#include <string>

using namespace std;

class Graphic {
public:
	virtual void Draw() = 0;
};

class Image : public Graphic {
public:
	Image(string str) {
		m_strFilename = str;
	}

	void Draw() {
		printf("Image::Draw(): %s\n", m_strFilename.c_str());
	}

private:
	string m_strFilename;
};

class ImageProxy : public Graphic {
public:
	ImageProxy(string str) {
		m_strFilename = str;
		m_pImage = NULL;
	}

	~ImageProxy() {
		if (m_pImage) {
			delete m_pImage;
		}
	}

	void Draw() {
		// Lazy load
		if (m_pImage == NULL) {
			m_pImage = new Image(m_strFilename);
		}
		m_pImage->Draw();
	}

private:
	string m_strFilename;
	Image *m_pImage;
};

class Document {
public:
	Document() {
		m_pImage = new ImageProxy("myfile.png");
	}

	~Document() {
		if (m_pImage) {
			delete m_pImage;
		}
	}

	void Scroll() {
		if (m_pImage) {
			m_pImage->Draw();
		}
	}

private:
	Graphic *m_pImage;
};

int main() {
	Document doc;
	doc.Scroll();
}
