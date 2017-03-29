import java.util.ArrayList;

abstract class Item {
	protected String m_strName;
	protected int m_iPrice = 0;

	public int Price() {
		return m_iPrice;
	}

	public String Name() {
		return m_strName;
	}
}

class Bread extends Item {
	public Bread() {
		m_strName = "Bread";
		m_iPrice = 20;
	}
}


class Burger extends Item {
	public Burger() {
		m_strName = "Burger";
		m_iPrice = 100;
	}
}


class Coke extends Item {
	public Coke() {
		m_strName = "Coke";
		m_iPrice = 10;
	}
}


class Meal {
	private ArrayList<Item> m_lstItem = new ArrayList<Item>();

	public void AddItem(Item item) {
		m_lstItem.add(item);
	}

	public int GetPrice() {
		int iCost = 0;
		for (Item item: m_lstItem) {
			iCost += item.Price();
		}

		return iCost;
	}

	public void ShowItems() {
		for (Item item: m_lstItem) {
			System.out.print(" "+item.Name());
		}
		System.out.println();
	}
}
			
class MealBuilder {
	public Meal OrderSet() {
		Meal meal = new Meal();
		meal.AddItem(new Bread());
		meal.AddItem(new Burger());
		meal.AddItem(new Coke());
		
		return meal;
	}

	public Meal OrderBurger() {
		Meal meal = new Meal();
		meal.AddItem(new Burger());

		return meal;
	}
}

public class Sample {
	public static void main(String[] args) {
		MealBuilder builder = new MealBuilder();
		Meal meal;

		System.out.println("Order set:");
		meal = builder.OrderSet();
		meal.ShowItems();
		System.out.println("Price: "+meal.GetPrice());

		System.out.println("Order burger:");
		meal = builder.OrderBurger();
		meal.ShowItems();
		System.out.println("Price: "+meal.GetPrice());
	}
}

