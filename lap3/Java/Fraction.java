public class Fraction {
	private int numerator, dinominator;
	public Fraction(){
	        numerator = 0;
	        dinominator = 1;
	    }

	public Fraction(int n, int d){
	        numerator = n;
	        dinominator = d;
	    }

	public Fraction(Fraction A){
	        this.numerator = A.numerator;
	        this.dinominator = A.dinominator;
	    }

	public Fraction add(Fraction B){
	        Fraction C = new Fraction();
	        C.numerator = this.numerator*B.dinominator + B.numerator*this.dinominator;
	        C.dinominator = this.dinominator * B.dinominator;
	        return C;
	    }
	public Fraction sub(Fraction B){
			Fraction C = new Fraction();
	        C.numerator = this.numerator*B.dinominator - B.numerator*this.dinominator;
	        C.dinominator = this.dinominator * B.dinominator;
	        return C;
	    }
	    boolean isEqualTo(Fraction B){
	        return ((double)(this.numerator)/(double)(this.dinominator) == (double)(B.numerator)/(double)(B.dinominator));
	    }
	public Fraction multiply(Fraction B){
			Fraction C = new Fraction();
	        C.numerator = this.numerator * B.numerator;
	        C.dinominator = this.dinominator * B.dinominator;
	        return C;
	    }

	    void display(){
	        if (numerator%dinominator == 0)
	            System.out.println(numerator/dinominator);
	        else
	        	System.out.println(numerator+"/"+dinominator);
	    }

	public static void main(String[] args) {
		Fraction A = new Fraction(2,5);
		System.out.print("Fraction A: ");
	    A.display();

	    Fraction B = new Fraction(3,7);
	    System.out.print("Fraction B: ");
	    B.display();

	    Fraction C = A.add(B);
	    System.out.print("Fraction C: ");
	    C.display();

	    Fraction D = A.sub(B);
	    System.out.print("Fraction D: ");
	    D.display();

	    Fraction E = A.multiply(B);
	    System.out.print("Fraction E: ");
	    E.display();

	    if (A==B)
	    	System.out.println("Fraction A is equal to B");
	    else
	    	System.out.println("Fraction A is not equal to B");
	}
}
