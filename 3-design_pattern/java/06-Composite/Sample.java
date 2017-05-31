import java.util.ArrayList;

abstract class Entry {
	protected int m_iSize;
	protected String m_strName;

	public String Name() {
		return m_strName;
	}

	public abstract int Size();
	public void Add(Entry entry) {}
	public abstract void Info(String strPrefix);
	public void Info() {
		Info("");
	}
}

class File extends Entry {
	public File(String strName, int iSize) {
		m_strName = strName;
		m_iSize = iSize;
	}

	public int Size() {
		return m_iSize;
	}

	public void Info(String strPrefix) {
		System.out.println(String.format("%s/%s (%d)", strPrefix, Name(), Size()));
	}
}

class Directory extends Entry {
	private ArrayList<Entry> m_lstEntry = new ArrayList<Entry>();

	public Directory(String strName) {
		m_strName = strName;
	}

	@Override
	public void Add(Entry entry) {
		m_lstEntry.add(entry);
	}

	public int Size() {
		int iSize = 0;
		for (Entry e: m_lstEntry) {
			iSize += e.Size();
		}

		return iSize;
	}

	public void Info(String strPrefix) {
		System.out.println(String.format("%s/%s (%d)", strPrefix, Name(), Size()));
		for (Entry e: m_lstEntry) {
			e.Info(strPrefix+"/"+Name());
		}
	}
}

public class Sample {
	public static void main(String[] args) {
		Directory windows = new Directory("windows");
		Directory system32 = new Directory("system32");
		windows.Add(system32);
		windows.Add(new File("dekstop.ini", 923));
		windows.Add(new File("taskman.exe", 15360));
		system32.Add(new File("shutdown.exe", 23552));

		windows.Info();
	}
}
