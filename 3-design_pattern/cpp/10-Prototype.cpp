#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class Prototype {
public:
	class Shape {
	public:
		virtual Shape* Clone() = 0;
		virtual void Draw() = 0;

	protected:
		string m_strType;
	};

public:
	Prototype() {
		// Two methods to put data into map
		m_map.insert(pair<string, Shape*>("Circle", new Circle()));
		m_map["Rectangle"] = new Rectangle();
	}

	~Prototype() {
		for (map<string, Shape*>::iterator it = m_map.begin(); it != m_map.end(); it++) {
			if (it->second != NULL) {
				//printf("delete: %s, %p\n", it->first.c_str(), it->second);
				delete it->second;
			}
		}
		m_map.clear();
	}

	Shape* MakeObject(string str) {
		map<string, Shape*>::iterator it = m_map.find(str);
		return (it != m_map.end() ? it->second->Clone() : NULL);
	}

private:
	class Circle : public Shape {
	public:
		Shape* Clone() {
			return new Circle();
		}

		void Draw() {
			printf("Draw: %s\n", m_strType.c_str());
		}

	private:
		friend class Prototype;

		Circle() {
			m_strType = "Circle";
		}

	};


	class Rectangle : public Shape {
	public:
		Shape* Clone() {
			return new Rectangle();
		}

		void Draw() {
			printf("Draw: %s\n", m_strType.c_str());
		}

	private:
		friend class Prototype;

		Rectangle() {
			m_strType = "Rectangle";
		}

	};

private:
	map<string, Shape*> m_map;

};

int main() {
	Prototype prop;
	Prototype::Shape *pShape;

	pShape = prop.MakeObject("Circle");
	pShape->Draw();

	pShape = prop.MakeObject("Rectangle");
	pShape->Draw();
}
