#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

enum { EPLAIN, EBOLD, EITALIC };

/*
 * Flyweight
 */
class Font {
public:
	Font(string str, int iStyle, int iSize) {
		m_strName = str;
		m_iStyle = iStyle;
		m_iSize = iSize;
	}

	bool Equals(string str, int iStyle, int iSize) {
		return (iStyle == m_iStyle && iSize == m_iSize && str == m_strName);
	}

private:
	string m_strName;
	int m_iStyle;
	int m_iSize;
};

/*
 * FlywieghtFactory
 */
class FontFactory {
public:
	~FontFactory() {
		for (int i = 0; i < m_ay.size(); i++) {
			delete m_ay[i];
		}

		m_ay.clear();
	}

	Font* Create(string str, int iStyle, int iSize) {
		Font *pFont = NULL;
		int iIdx;

		if ((iIdx = _InCache(str, iStyle, iSize)) != -1) {
			pFont = m_ay[iIdx];
		} else {
			pFont = new Font(str, iStyle, iSize);
			m_ay.push_back(pFont);
		}

		return pFont;
	}

private:
	vector<Font*> m_ay;

	int _InCache(string str, int iStyle, int iSize) {
		for (int i = 0; i < m_ay.size(); i++) {
			if (m_ay[i]->Equals(str, iStyle, iSize)) {
				return i;
			}
		}

		return -1;
	}
};
		

int main() {
	FontFactory factory;
	Font *pFont1 = factory.Create("Arial", EBOLD, 12);
	Font *pFont2 = factory.Create("Arial", EBOLD, 12);
	printf("font1: %p, font2: %p\n", pFont1, pFont2);
}
