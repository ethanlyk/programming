class Exit {
	private Mediator m_mediator;

	public Exit(Mediator obj) {
		m_mediator = obj;
	}

	public void Execute() {
		System.out.println("exit");
	}
}

class Browse {
	private Mediator m_mediator;

	public Browse(Mediator obj) {
		m_mediator = obj;
	}

	public void Execute() {
		System.out.println("shop.purchase");
		m_mediator.Handle("shop.purchase");
	}
}

class Welcome {
	private Mediator m_mediator;

	public Welcome(Mediator obj) {
		m_mediator = obj;
	}

	public void Execute() {
		System.out.println("welcome.shop");
		m_mediator.Handle("welcome.shop");
	}
}

class Purchase {
	private Mediator m_mediator;

	public Purchase(Mediator obj) {
		m_mediator = obj;
	}

	public void Execute() {
		System.out.println("Thanks for your purchase.");
		m_mediator.Handle("purchase.exit");
	}
}

class Mediator {
	Welcome m_welcome;
	Browse m_browse;
	Purchase m_purchase;
	Exit m_exit;

	public Mediator() {
		m_welcome = new Welcome(this);
		m_browse = new Browse(this);
		m_purchase = new Purchase(this);
		m_exit = new Exit(this);
	}

	public void Handle(String strState) {
		if (strState.equals("welcome.shop")) {
			m_browse.Execute();
		} else if (strState.equals("shop.purchase")) {
			m_purchase.Execute();
		} else if (strState.equals("welcome.exit")) {
			m_exit.Execute();
		} else if (strState.equals("shop.exit")) {
			m_exit.Execute();
		} else if (strState.equals("purchase.exit")) {
			m_exit.Execute();
		}
	}

	public Welcome GetWelcome() {
		return m_welcome;
	}
}

public class Sample {
	public static void main(String[] args) {
		Mediator mediator = new Mediator();
		mediator.GetWelcome().Execute();
	}
}
