#include <iostream>
#include <string>
#include <list>

using namespace std;

class Item {
public:
	int Price() {
		return m_iPrice;
	}

	string Name() {
		return m_strName;
	}

protected:
	int m_iPrice;
	string m_strName;
};

class Bread : public Item {
public:
	Bread() {
		m_strName = "Bread";
		m_iPrice = 20;
	}
};

class Burger : public Item {
public:
	Burger() {
		m_strName = "Burger";
		m_iPrice = 100;
	}
};

class Coke : public Item {
public:
	Coke() {
		m_strName = "Coke";
		m_iPrice = 10;
	}
};

class Meal {
public:
	~Meal() {
		m_lstItem.clear();
	}

	void AddItem(Item &item) {
		m_lstItem.push_back(item);
	}

	void ShowItems() {
		for (list<Item>::iterator it = m_lstItem.begin(); it != m_lstItem.end(); it++) {
			cout << " " << (*it).Name();
		}
		cout << endl;
	}

	int GetPrice() {
		int iCost = 0;
		for (list<Item>::iterator it = m_lstItem.begin(); it != m_lstItem.end(); it++) {
			iCost += (*it).Price();
		}
		
		return iCost;
	}

private:
	list<Item> m_lstItem;
};

class MealBuilder {
public: 
	static Meal OrderSet() {
		Meal meal;

		Bread bread;
		meal.AddItem(bread);

		Burger burger;
		meal.AddItem(burger);

		Coke coke;
		meal.AddItem(coke);

		return meal;
	}

	static Meal OrderBurger() {
		Meal meal;

		Burger burger;
		meal.AddItem(burger);

		return meal;
	}
};

int main() {
	cout << "Order set:\n";
	Meal meal1 = MealBuilder::OrderSet();
	meal1.ShowItems();
	cout << "Price: " << meal1.GetPrice() << endl;

	cout << "\nOrder burger:\n";
	Meal meal2 = MealBuilder::OrderBurger();
	meal2.ShowItems();
	cout << "Price: " << meal2.GetPrice() << endl;

}

