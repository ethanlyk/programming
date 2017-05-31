
abstract class UIComponent {
	private int m_iX, m_iY;

	public void Set(int iX, int iY) {
		m_iX = iX;
		m_iY = iY;
	}

	abstract void Draw();
}

class Image extends UIComponent {
	String m_strSource;

	public Image(String strSource) {
		m_strSource = strSource;
	}

	@Override
	public void Draw() {
		System.out.println("Image::Draw(): "+m_strSource);
	}
}

class Button extends UIComponent {
	Image m_image;

	public Button(Image img) {
		m_image = img;
	}

	public Button(String strSource) {
		m_image = new Image(strSource);
	}

	@Override
	public void Draw() {
		System.out.println("Button::Draw()");
	}

	public void Click() {
		System.out.println("Button::Click()");
	}
}

public class Sample {
	public static void main(String[] args) {
		Image img = new Image("myjpg.jpg");
		img.Draw();

		Button btn = new Button(img);
		btn.Click();
	}
}
