#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

class Document {
public:
	Document(int iData, string strName) {
		m_iData = iData;
		m_strName = strName;
	}

	string GetName() {
		return m_strName;
	}

	int GetData() {
		return m_iData;
	}

	bool IsSuccess() {
		return m_bSuccess;
	}

	void SetSuccess(bool bSuccess) {
		m_bSuccess = bSuccess;
	}

private:
	int m_iData;
	string m_strName;
	bool m_bSuccess;
};

/*
 * Handler
 */
class Format {
public:
	virtual Document* HandleRequest(int iRequest) = 0;
	virtual ~Format() {} // virtual destructor is neccessary

protected:
	Document* m_pDoc;

	virtual Document* SetSuccess(int iRequest) {
		if (m_pDoc) {
			m_pDoc->SetSuccess(m_pDoc->GetData() == iRequest);
		}

		return m_pDoc;
	}

};

class EnlargeFont : public Format {
public:
	~EnlargeFont() {
		if (m_pDoc) {
			delete m_pDoc;
		}
	}

	Document* HandleRequest(int iRequest) {
		printf("Trying EnlargeFont\n");
		m_pDoc = new Document(1, "EnlargeFont");
		return SetSuccess(iRequest);
	}
};

class ChangeColor : public Format {
public:
	~ChangeColor() {
		if (m_pDoc) {
			delete m_pDoc;
		}
	}

	Document* HandleRequest(int iRequest) {
		printf("Trying ChangeColor\n");
		m_pDoc = new Document(2, "ChangeColor");
		return SetSuccess(iRequest);
	}
};

class AddHeader : public Format {
public:
	~AddHeader() {
		if (m_pDoc) {
			delete m_pDoc;
		}
	}

	Document* HandleRequest(int iRequest) {
		printf("Trying AddHeader\n");
		m_pDoc = new Document(3, "AddHeader");
		return SetSuccess(iRequest);
	}
};

class AddFooter : public Format {
public:
	~AddFooter() {
		if (m_pDoc) {
			delete m_pDoc;
		}
	}

	Document* HandleRequest(int iRequest) {
		printf("Trying AddFooter\n");
		m_pDoc = new Document(4, "AddFooter");
		return SetSuccess(iRequest);
	}
};

class DocumentFormat {
public:
	DocumentFormat() {
		m_ayFormat.push_back(new EnlargeFont());
		m_ayFormat.push_back(new ChangeColor());
		m_ayFormat.push_back(new AddHeader());
		m_ayFormat.push_back(new AddFooter());
	}

	~DocumentFormat() {
		for (int i = 0; i < m_ayFormat.size(); i++) {
			if (m_ayFormat[i]) {
				delete m_ayFormat[i];
			}
		}
		m_ayFormat.clear();
	}

	Document* Solve(int iRequest) {
		for (int i = 0; i < m_ayFormat.size(); i++) {
			Document *pDoc = m_ayFormat[i]->HandleRequest(iRequest);
			if (pDoc->IsSuccess()) {
				return pDoc;
			}
		}

		return NULL;
	}

private:
	vector<Format*> m_ayFormat;
};

int main() {
	DocumentFormat docft;

	int iRequest = 3;
	Document *pDoc = docft.Solve(iRequest);
	printf("Request %d => ", iRequest);
	printf("%s\n", (pDoc) ? pDoc->GetName().c_str() : "Unsolved");
}

