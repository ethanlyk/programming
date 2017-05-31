/*
 * State
 */
interface IAnimal {
	String Talk();
}

class Frog implements IAnimal {
	public String Talk() {
		return "ggg!";
	}
}

class Cat implements IAnimal {
	public String Talk() {
		return "miao";
	}
}

/*
 * Context
 */
class Creature {
	private IAnimal m_state = new Frog();

	public void Greet() {
		System.out.println(m_state.Talk());
	}

	public void ToCat() {
		m_state = new Cat();
	}
}

public class Sample {
	public static void main(String[] args) {
		Creature creature = new Creature();
		creature.Greet();
		
		creature.ToCat();
		creature.Greet();
	}
}
