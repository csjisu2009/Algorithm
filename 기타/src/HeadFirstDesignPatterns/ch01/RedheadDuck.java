package HeadFirstDesignPatterns.ch01;

public class RedheadDuck extends Duck{
	public RedheadDuck() {
		flyBehavior = new FlyWithWings();
		quackBehavior = new Quack();
	}

	@Override
	public void display() {
		// TODO Auto-generated method stub
		System.out.println("I'm a ReadheadDuck~");
	}
}
