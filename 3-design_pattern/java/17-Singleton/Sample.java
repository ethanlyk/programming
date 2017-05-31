
class Singleton {
	private static Singleton m_Instance = null;

	private Singleton() {}

	public static Singleton Instance() {
		if (m_Instance == null) {
			m_Instance = new Singleton();
		}

		return m_Instance;
	}

	public void Do() {
		System.out.println("Do something");
	}
}

public class Sample {
	public static void main(String[] args) {
		//Singleton instance = new Singleton(); // NG
		Singleton instance = Singleton.Instance();

		instance.Do();
	}
}
