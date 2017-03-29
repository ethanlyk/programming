#include <iostream>
#include <string>

using namespace std;

class Product {
public:
	string GetName() {
		return m_strName;
	}

protected:
	string m_strName;
};

class ProductA : public Product {
public:
	ProductA(string str) {
		m_strName = str;
	}
};

class ProductB : public Product {
public:
	ProductB(string str) {
		m_strName = str;
	}
};

class SimpleFactory {
public:
	static Product* Create(string str) {
		if (str == "A") {
			return new ProductA(str);
		} else if (str == "B") {
			return new ProductB(str);
		}

		return NULL;
	}
};

int main() {
	Product *pObj;
	string str;

	str = "A";
	pObj = SimpleFactory::Create(string(str));
	cout << "Create ProductA => Got: " << pObj->GetName() << endl;

	str = "B";
	pObj = SimpleFactory::Create(string(str));
	cout << "Create ProductB => Got: " << pObj->GetName() << endl;

	delete pObj;
}
