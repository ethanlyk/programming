/*
 * 一个对象被回收, 必须满足两个条件: 1)没有任何引用指向它 2)GC被运行.
 *
 * a. Strong reference: 一般的指定即為 strong reference
 * b. Weak reference: 当一个对象仅仅被weak reference指向, 而没有任何其他strong reference指向的时候, 
 *    如果GC运行, 那么这个对象就会被回收.
 * c. Soft reference: 和weak reference一样, 但被GC回收的时候需要多一个条件: 当系统内存不足时, 
 *    soft reference指向的object才会被回收.
 */

import java.util.HashMap;
import java.lang.ref.WeakReference;

class Style {
	final static int PLAIN = 1;
	final static int BOLD = 2;
	final static int ITALIC = 3;
}

/*
 * Flyweight
 */
class Font {
	private String m_strName;
	private int m_iStyle;
	private int m_iSize;

	public Font(String str, int iStyle, int iSize) {
		m_strName = str;
		m_iStyle = iStyle;
		m_iSize = iSize;
	}

	public boolean equals(Object obj) {
		if (obj instanceof Font) {
			if (obj == this) {
				return true;
			}

			Font font = (Font)obj;
			return (font.m_iStyle == m_iStyle && font.m_iSize == m_iSize && font.m_strName.equals(m_strName));
		}

		return false;
	}

	public int hashCode() {
		return (m_iStyle*37 + m_iSize*13) * m_strName.hashCode();
	}
}

/*
 * FlyweightFactory
 */
class FontFactory {
	private static HashMap<Font, WeakReference<Font>> m_map = new HashMap<Font, WeakReference<Font>>();

	public static Font Create(String str, int iStyle, int iSize) {
		Font font = new Font(str, iStyle, iSize);

		if (!m_map.containsKey(font)) {
			m_map.put(font, new WeakReference<Font>(font));
		}

		return m_map.get(font).get();
	}
}


public class Sample {
	public static void main(String[] args) {
		Font font1 = FontFactory.Create("Arial", Style.BOLD, 12);
		Font font2 = FontFactory.Create("Arial", Style.BOLD, 12);

		System.out.println("font1 == font2 ?\n  => "+(font1==font2));
	}
}

