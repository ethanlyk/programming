class Adaptee {
	public void DoAdaptee() {
		System.out.println("DoAdaptee()\n");
	}
}

interface IAdapter {
	void Request();
}


// Use Adaptee as delegation
class Adapter implements IAdapter {
	private Adaptee m_adptee = new Adaptee();

	public void Request() {
		m_adptee.DoAdaptee();
	}
}

public class Sample {
	public static void main(String[] args) {
		Adapter obj = new Adapter();
		obj.Request();
	}
}
