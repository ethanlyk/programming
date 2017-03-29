interface IStrategy {
	void Do();
}

class StrategyA implements IStrategy {

	@Override
	public void Do() {
		System.out.println("StrategyA do");
	}
}


class StrategyB implements IStrategy {

	@Override
	public void Do() {
		System.out.println("StrategyB do");
	}
}


public class Sample {
	public static void main(String[] args) {
		IStrategy obj;

		if (args.length != 0) {
			obj = new StrategyA();
		} else {
			obj = new StrategyB();
		}

		obj.Do();
	}
}

