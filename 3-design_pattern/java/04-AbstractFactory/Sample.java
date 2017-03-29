/********** Product *********/
interface IBall {
	void Action();
}

class Basketball implements IBall {
	public void Action() {
		System.out.println("Hand pass");
	}
}

class Football implements IBall {
	public void Action() {
		System.out.println("Foot pass");
	}
}

interface IPlayer {
	void Kick(IBall ball);
}

class PlayerA implements IPlayer {
	public void Kick(IBall ball) {
		System.out.println("PlayerA");
		ball.Action();
	}
}

class PlayerB implements IPlayer {
	public void Kick(IBall ball) {
		System.out.println("PlayerB");
		ball.Action();
	}
}

/********** Factory *********/
interface IGameFactory {
	IPlayer MakePlayer();
	IBall MakeBall();
}

class BasketballFactory implements IGameFactory {
	public IPlayer MakePlayer() {
		return new PlayerA();
	}

	public IBall MakeBall() {
		return new Basketball();
	}
}

class FootballFactory implements IGameFactory {
	public IPlayer MakePlayer() {
		return new PlayerB();
	}

	public IBall MakeBall() {
		return new Football();
	}
}

/******************************/
class Match {
	private IPlayer m_player;
	private IBall m_ball;

	public Match(IGameFactory factory) {
		m_player = factory.MakePlayer();
		m_ball = factory.MakeBall();
	}

	public void Play() {
		m_player.Kick(m_ball);
	}
}

public class Sample {
	public static void main(String[] args) {
		Match match;
	 
		System.out.println("Play basketball");
		match	= new Match(new BasketballFactory());
		match.Play();
	 
		System.out.println("\nPlay football");
		match	= new Match(new FootballFactory());
		match.Play();
	}
}
