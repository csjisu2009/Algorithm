package HeadFirstDesignPatterns.ch01;

public class MiniDuckSimulator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Duck mallard = new MallardDuck();
		mallard.performQuack();
		mallard.performFly();
		
		Duck redhead = new RedheadDuck();
		redhead.performQuack();
		redhead.performFly();
		
		Duck rubber = new RubberDuck();
		rubber.performQuack();
		rubber.performFly();
		
		Duck decoy = new DecoyDuck();
		decoy.performQuack();
		decoy.performFly();
		
	}

}
