import java.util.ArrayList;

/********** Product **********/
abstract class Document {
	protected String m_strTitle;

	abstract void Open();
	abstract void Close();
}

class Text extends Document {
	public Text(String strTitle) {
		m_strTitle = strTitle;
	}

	public void Open() {
		System.out.println("\tText::Open("+m_strTitle+")");
	}

	public void Close() {
		System.out.println("\tText::Close("+m_strTitle+")");
	}
}

class Image extends Document {
	public Image(String strTitle) {
		m_strTitle = strTitle;
	}

	public void Open() {
		System.out.println("\tImage::Open("+m_strTitle+")");
	}

	public void Close() {
		System.out.println("\tImage::Close("+m_strTitle+")");
	}
}

/********** Factory **********/
interface IEditor {
	Document Open(String strTitle);
	void Close();
}

class TextEditor implements IEditor {
	private ArrayList<Document> m_lstDoc = new ArrayList<Document>();

	public Document Open(String strTitle) {
		Document doc = new Text(strTitle);
		doc.Open();
		m_lstDoc.add(doc);

		return doc;
	}

	public void Close() {
		for (Document doc: m_lstDoc) {
			doc.Close();
		}
		m_lstDoc.clear();
	}
}

class ImageEditor implements IEditor {
	private Document m_doc;

	public Document Open(String strTitle) {
		m_doc = new Image(strTitle);
		m_doc.Open();

		return m_doc;
	}

	public void Close() {
		m_doc.Close();
	}
}

/********************************************/
public class Sample {
	public static void main(String[] args) {
		IEditor editor;

		System.out.println("Create text editor:");
		editor	= new TextEditor();
		editor.Open("file1.txt");
		editor.Open("file2.txt");
		editor.Close();

		System.out.println("Create image editor:");
		editor	= new ImageEditor();
		editor.Open("image1.png");
		editor.Close();
	}
}

