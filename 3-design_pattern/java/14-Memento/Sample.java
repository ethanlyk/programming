import java.util.ArrayList;
import java.util.Date;

/*
 * Memento
 */
class Backup {
	private String m_strState;
	private Date m_date;

	public Backup(String str) {
		m_strState = str;
		m_date = new Date();
	}

	public Date GetDate() {
		return m_date;
	}

	public String GetState() {
		return m_strState;
	}
}

/*
 * CareTaker
 */
class Recovery {
	private ArrayList<Backup> m_ayBackup = new ArrayList<Backup>();

	public void Add(Backup backup) {
		m_ayBackup.add(backup);
	}

	public Backup Retrieve(Date date) {
		for (Backup backup: m_ayBackup) {
			if (backup.GetDate().equals(date)) {
				m_ayBackup.remove(backup);
				return backup;
			}
		}

		return null;
	}
}

/*
 * Originator
 */
class Application {
	private String m_strState = "default setting";

	public Backup DoBackup() {
		return new Backup(m_strState);
	}

	public void Recover(Backup backup) {
		m_strState = backup.GetState();
	}

	public void SetState(String str) {
		m_strState = str;
	}

	public String GetState() {
		return m_strState;
	}
}


public class Sample {
	public static void main(String[] args) {
		Application application = new Application();
		Recovery recovery = new Recovery();

		System.out.println("Origin: "+application.GetState());

		Backup backup = application.DoBackup();
		recovery.Add(backup);

		application.SetState("mysetting");
		System.out.println("New: "+application.GetState());

		Date date = backup.GetDate();
		application.Recover(recovery.Retrieve(date));
		System.out.println("Recover: "+application.GetState());
	}
}

