import java.util.ArrayList;

/*
 * Observer
 */
interface IAlarm {
	void Update();
}

class Light implements IAlarm {
	public void Update() {
		System.out.println("Light::Alarm()");
	}
}

class Gate implements IAlarm {
	public void Update() {
		System.out.println("Gate::Alarm()");
	}
}

/*
 * Subject
 */
class SensorSystem {
	private ArrayList<IAlarm> m_lstSensor = new ArrayList<IAlarm>();

	public void Attach(IAlarm obj) {
		m_lstSensor.add(obj);
	}

	public void Notify() {
		for (IAlarm obj: m_lstSensor) {
			obj.Update();
		}
	}
	public void Release() {
		m_lstSensor.clear();
	}
}


public class Sample {
	public static void main(String[] args) {
		SensorSystem system = new SensorSystem();
		system.Attach(new Light());
		system.Attach(new Gate());
		
		system.Notify();

		system.Release();
	}
}
