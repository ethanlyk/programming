interface Graphic {
	void Draw();
}

class Image implements Graphic {
	private String m_strFilename;

	Image(String str) {
		m_strFilename = str;
	}

	public void Draw() {
		System.out.println("Image::Draw(): "+m_strFilename);
	}
}

class ImageProxy implements Graphic {
	private Graphic m_image;
	private String m_strFilename;

	ImageProxy(String str) {
		m_strFilename = str;
	}

	public void Draw() {
		// Lazy load
		if (m_image == null) {
			m_image = new Image(m_strFilename);
		}
		m_image.Draw();
	}
}

class Document {
	private Graphic m_image;

	Document() {
		m_image = new ImageProxy("myfile.png");
	}

	void Scroll() {
		m_image.Draw();
	}
}

public class Sample {
	public static void main(String[] args) {
		Document doc = new Document();
		doc.Scroll();
	}
}
