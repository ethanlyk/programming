#include <iostream>
#include <string>
#include <list>

using namespace std;

/********** Product **********/
class Document {
public:
	virtual void Open() = 0;
	virtual void Close() = 0;

protected:
	string m_strTitle;
};

class Text : public Document {
public:
	Text(string str) {
		m_strTitle = str;
	}

	void Open() {
		cout << "\tText::Open(" << m_strTitle << ")" << endl;
	}

	void Close() {
		cout << "\tText::Close(" << m_strTitle << ")" << endl;
	}
};

class Image : public Document {
public:
	Image(string str) {
		m_strTitle = str;
	}

	void Open() {
		cout << "\tImage::Open(" << m_strTitle << ")" << endl;
	}

	void Close() {
		cout << "\tImage::Close(" << m_strTitle << ")" << endl;
	}
};

/********** Factory **********/
class IEditor {
public:
	virtual Document* Open(string str) = 0;
	virtual void Close() = 0;
};

class TextEditor : public IEditor {
public:
	Document* Open(string str) {
		Document *pDoc = new Text(str);
		pDoc->Open();
		m_lstDoc.push_back(pDoc);
		
		return pDoc;
	}

	void Close() {
		for (list<Document*>::iterator it = m_lstDoc.begin(); it != m_lstDoc.end(); it++) {
			(*it)->Close();
			delete (*it);
		}
		m_lstDoc.clear();
	}

private:
	list<Document*> m_lstDoc;
};

class ImageEditor : public IEditor {
public:
	Document* Open(string str) {
		m_doc = new Image(str);
		m_doc->Open();
		
		return m_doc;
	}

	void Close() {
		m_doc->Close();
		delete m_doc;
	}

private:
	Document* m_doc;
};

/********** main **********/
int main() {
	IEditor *editor;

	cout << "Create text editor\n";
	editor = new TextEditor();
	editor->Open("file1.txt");
	editor->Open("file2.txt");
	editor->Close();

	cout << "Create image editor\n";
	editor = new ImageEditor();
	editor->Open("image.png");
	editor->Close();

	delete editor;
}
