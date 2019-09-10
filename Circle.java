
public class Circle {
	private double radius;
	public Circle(double value) {
		radius = value;
	}
	public double perimeter() {
		return 2*Math.PI*radius;
	}
	public double area() {
		return Math.PI*Math.pow(radius,2);
	}
	public static void main(String[] args) {
		Circle circ1, circ2;
		circ1 = new Circle(18);
		circ2 = new Circle(16);
		System.out.println("area of circ1 is: "+circ1.area());
		System.out.println("perimeter of circ1 is: "+circ1.perimeter());
		System.out.println("area of circ2 is: "+circ2.area());
		System.out.println("perimeter of circ2 is: "+circ2.perimeter());
	}
}
