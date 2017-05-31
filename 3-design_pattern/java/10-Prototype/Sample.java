import java.util.HashMap;

class Prototype {
	interface IClone {
		Shape Clone();
	}

	abstract class Shape implements IClone {
		protected String m_strType;

		abstract void Draw();
	}

	class Circle extends Shape {
		private Circle() {
			m_strType = "Circle";
		}

		public Shape Clone() {
			return new Circle();
		}

		public void Draw() {
			System.out.println("Draw: "+m_strType);
		}
	}

	class Rectangle extends Shape {
		private Rectangle() {
			m_strType = "Rectangle";
		}

		public Shape Clone() {
			return new Rectangle();
		}

		public void Draw() {
			System.out.println("Draw: "+m_strType);
		}
	}

	private HashMap<String, Shape> m_mapPrototype = new HashMap<String, Shape>();

	public Prototype() {
		m_mapPrototype.put("Circle", new Circle());
		m_mapPrototype.put("Rectangle", new Rectangle());
	}

	public Shape MakeObject(String strType) {
		return (m_mapPrototype.containsKey(strType) ? m_mapPrototype.get(strType).Clone() : null);
	}
}

public class Sample {
	public static void main(String[] args) {
		Prototype prototype = new Prototype();

		Prototype.Shape shape;
		shape = prototype.MakeObject("Circle");
		shape.Draw();
		shape = prototype.MakeObject("Rectangle");
		shape.Draw();
	}
}

