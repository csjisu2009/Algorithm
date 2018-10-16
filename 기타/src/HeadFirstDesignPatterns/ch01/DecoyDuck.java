package HeadFirstDesignPatterns.ch01;

public class DecoyDuck extends Duck{
	public DecoyDuck() {
		flyBehavior = new FlyNoWay();
		quackBehavior = new MuteQuack();
	}
	
	@Override
	public void display() {
		// TODO Auto-generated method stub
		System.out.println("I'm a DecoyDuck~");
	}
	
}
