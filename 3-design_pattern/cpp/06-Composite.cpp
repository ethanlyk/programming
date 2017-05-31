#include <iostream>
#include <string>
#include <list>

using namespace std;

class Entry {
public:
	string Name() {
		return m_strName;
	}

	virtual int Size() = 0;
	virtual void Add(Entry* pEntry) {}
	virtual void Info(string strPrefix) = 0;
	
	//virtual void Info(); // Compile failed due to 隱藏(Hiding)

protected:
	string m_strName;
	int m_iSize;
};

class File : public Entry {
public:
	File(string strName, int iSize) {
		m_strName = strName;
		m_iSize = iSize;
	}

	int Size() {
		return m_iSize;
	}

	void Info(string strPrefix) {
		cout << strPrefix << "/" << Name() << "(" << Size() << ")" << endl;
	}
};

class Directory : public Entry {
public:
	Directory(string strName) {
		m_strName = strName;
	}

	~Directory() {
		m_lstEntry.clear();
	}

	int Size() {
		int iSize = 0;
		for (list<Entry*>::iterator it = m_lstEntry.begin(); it != m_lstEntry.end(); it++) {
			iSize += (*it)->Size();
		}

		return iSize;
	}

	void Add(Entry* pEntry) {
		m_lstEntry.push_back(pEntry);
	}

	void Info(string strPrefix) {
		cout << strPrefix << "/" << Name() << "(" << Size() << ")" << endl;
		for (list<Entry*>::iterator it = m_lstEntry.begin(); it != m_lstEntry.end(); it++) {
			string str = strPrefix+"/"+Name();
			(*it)->Info(str);
		}
	}

private:
	list<Entry*> m_lstEntry;
};


int main() {
	Directory *pWindows = new Directory("windows");
	Directory *pSystem = new Directory("system32");
	pWindows->Add(pSystem);
	File *pFile1 = new File("desktop.ini", 923);
	pWindows->Add(pFile1);
	File *pFile2 = new File("taskman.exe", 15360);
	pWindows->Add(pFile2);
	File *pFile3 = new File("shutdown.exe", 23552);
	pSystem->Add(pFile3);

	pWindows->Info("");

	delete pFile1;
	delete pFile2;
	delete pFile3;
	delete pSystem;
	delete pWindows;
}
	
