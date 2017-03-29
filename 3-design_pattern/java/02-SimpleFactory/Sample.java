abstract class Product {
	String m_strName;

	public String GetName() {
		return m_strName;
	}
}

class ProductA extends Product {
	public ProductA(String str) {
		m_strName = str;
	}
}

class ProductB extends Product {
	public ProductB(String str) {
		m_strName = str;
	}
}

class SimpleFactory {
	public static Product Create(String str) {
		if (str == "A") {
			return (new ProductA(str));
		} else if (str == "B") {
			return (new ProductB(str));
		}

		return null;
	}
}

/********************************************/
public class Sample {
	public static void main(String[] args) {
		Product p;
	   	
		p = SimpleFactory.Create("A");
		System.out.println("Create A => Got: "+p.GetName());

		p = SimpleFactory.Create("B");
		System.out.println("Create B => Got: "+p.GetName());
	}
}

