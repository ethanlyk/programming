import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.util.Random;

/*
 * Element
 */
interface IFriend {
	void Accept(IVisitor v);
}

class FriendsInHighSchool implements IFriend {
	public void Accept(IVisitor v) {
		v.Visit(this);
	}
}

class FriendsFromNeighbor implements IFriend {
	public void Accept(IVisitor v) {
		v.Visit(this);
	}
}

class NewFriends implements IFriend {
	public void Accept(IVisitor v) {
		v.Visit(this);
	}
}

/*
 * ObjectStructures
 */
class FriendsGenerator {
	private static Random rand = new Random();

	public static IFriend NewFlower() {
		switch (rand.nextInt(3)) {
			case 0:
				return new FriendsInHighSchool();

			case 1:
				return new FriendsFromNeighbor();

			case 2:
			default:
				return new NewFriends();
		}
	}
}


/*
 * Visitor
 */
interface IVisitor {
	void Visit(FriendsInHighSchool f);
	void Visit(FriendsFromNeighbor f);
	void Visit(NewFriends f);
}

class Party implements IVisitor {
	public void Visit(FriendsInHighSchool f) {
		System.out.println("FriendsInHighSchool");
	}

	public void Visit(FriendsFromNeighbor f) {
		System.out.println("FriendsFromNeighbor");
	}

	public void Visit(NewFriends f) {
		System.out.println("NewFriends");
	}
}

class Drink implements IVisitor {
	public void Visit(FriendsInHighSchool f) {
		System.out.println("Drink and FriendsInHighSchool");
	}

	public void Visit(FriendsFromNeighbor f) {
		System.out.println("Drink and FriendsFromNeighbor");
	}

	public void Visit(NewFriends f) {
		System.out.println("Drink and NewFriends");
	}
}

public class Sample {
	public static void main(String[] args) {
		ArrayList<IFriend> lstFriend = new ArrayList<IFriend>();

		for (int i = 0; i < 10; i++) {
			lstFriend.add(FriendsGenerator.NewFlower());
		}

		Party party = new Party();
		Iterator it = lstFriend.iterator();
		while (it.hasNext()) {
			((IFriend)it.next()).Accept(party);
		}

		System.out.println("");

		Drink drink = new Drink();
		it = lstFriend.iterator();
		while (it.hasNext()) {
			((IFriend)it.next()).Accept(drink);
		}
	}
}
