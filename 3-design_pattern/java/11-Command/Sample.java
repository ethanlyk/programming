import java.util.HashMap;

/*
 * Receiver
 */
class Effect {
	public void DoEffect1() {
		System.out.println("\tDo effect1");
	}

	public void DoEffect2() {
		System.out.println("\tDo effect2");
	}

	public void DoEffect3() {
		System.out.println("\tDo effect3");
	}
}

/*
 * Command
 */
abstract class Command {
	protected Effect m_effect;

	public abstract void Execute();
}

class AEffectCommand extends Command {
	public AEffectCommand(Effect e) {
		m_effect = e;
	}

	public void Execute() {
		System.out.println("Do AEffect");
		m_effect.DoEffect1();
		m_effect.DoEffect2();
	}
}

class BEffectCommand extends Command {
	public BEffectCommand(Effect e) {
		m_effect = e;
	}

	public void Execute() {
		System.out.println("Do BEffect");
		m_effect.DoEffect2();
		m_effect.DoEffect3();
	}
}

/*
 * Invoker
 */
class ImageService {
	private HashMap<String, Command> m_map = new HashMap<String, Command>();

	public void AddCommand(String str, Command cmd) {
		m_map.put(str, cmd);
	}

	public void Do(String str) {
		if (m_map.containsKey(str)) {
			m_map.get(str).Execute();
		} else {
			System.out.println("No such effect: "+str);
		}
	}
}

public class Sample {
	public static void main(String args[]) {
		Effect effect = new Effect();

		ImageService service = new ImageService();
		service.AddCommand("AEffect", new AEffectCommand(effect));
		service.AddCommand("BEffect", new BEffectCommand(effect));

		service.Do("AEffect");
		service.Do("BEffect");
		service.Do("CEffect");
	}
}
