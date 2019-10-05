
import java.util.Scanner;

public class Matrix {
    private int n;            						 // number of rows
    private int m;            						 // number of columns
    private float data[][] = new float[100][100];  	 // M-by-N array

    //Construcror allows user to enter values for a matrix from keyboard
    public Matrix(){
    	Scanner sc = new Scanner(System.in);
    	System.out.println("Input number of rows: ");
    	n =  sc.nextInt();
    	System.out.println("Input number of columns: ");
    	m=  sc.nextInt();
    	for (int i=0; i<n; i++)
    		for (int j=0; j<m; j++) {
    			System.out.print("data["+i+"]["+j+"]= ");
    	        data[i][j] =  sc.nextFloat();
    		}
    }
    
    // create M-by-N matrix of 0's
    public Matrix(int N, int M) {
    	n = N;
    	m = M;
    	for (int i=0; i<n; i++)
    		for (int j=0; j<m; j++) {
    			data[i][j] = 0;
    		}
    }

    // create matrix based on 2d array
    public Matrix(float[][] a, int row, int col) {
       for(int i=0; i<row; i++)
    	   for(int j=0; j<col; j++)
    		   data[i][j] = a[i][j];
    }

    // copy constructor
    private Matrix(Matrix A) { 
    	n=A.n;
    	m=A.m;
    	for(int i=0; i<n; i++)
    		for(int j=0; j<m; j++)
    			this.data[i][j] = A.data[i][j];
    }

    // return C = A + B
    public Matrix add(Matrix B) {
        Matrix C = new Matrix(B.n, B.m);
    	if (n == B.n && m == B.m) {
        	for(int i=0; i<n; i++)
        		for(int j=0; j<m; j++)
        			C.data[i][j] = this.data[i][j] + B.data[i][j];
        }
        return C;
    }


    // return C = A - B
    public Matrix sub(Matrix B) {
    	Matrix C = new Matrix(B.n, B.m);
    	if (n == B.n && m == B.m) {
        	for(int i=0; i<n; i++)
        		for(int j=0; j<m; j++)
        			C.data[i][j] = this.data[i][j] - B.data[i][j];
        }
        return C;
    }

    // does A = B exactly?
    public boolean equal(Matrix B) {
    	if (n == B.n && m == B.m) {
        	for(int i=0; i<n; i++)
        		for(int j=0; j<m; j++) 
        			if(this.data[i][j]!=B.data[i][j])
        				return false;
        	return true;
        }
        return false;
    }

    // return C = A * B
    public Matrix multiply(Matrix B) {
    	Matrix C = new Matrix(B.n, B.m);
    	if (n == B.n && m == B.m) {
        	for(int i=0; i<n; i++)
        		for(int j=0; j<m; j++)
        			C.data[i][j] = this.data[i][j] * B.data[i][j];
        }
        return C;
    }    
    
    // print matrix to standard output
    public void display() {
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++)  
                System.out.print(data[i][j]+" ");
        	System.out.println();
        }
    }

    // test client
    public static void main(String[] args) {
        Matrix A = new Matrix();
        System.out.println("Matrix A:");
        A.display();        
        System.out.println();

        Matrix B = new Matrix(A);
        System.out.println("Matrix B:");
        B.display();        
        System.out.println();

        Matrix C = A.add(B);
        System.out.println("Matrix C:");
        C.display(); 
        System.out.println();

        Matrix D = A.sub(B);
        System.out.println("Matrix D:");
        D.display(); 
        System.out.println();

        Matrix E = A.multiply(B);
        System.out.println("Matrix E:");
        E.display(); 
        System.out.println();

        // shouldn't be equal since AB != BA in general    
        if(A.equal(B))
        	System.out.println("Matrix A is equal to matrix B");
        else
        	System.out.println("Matrix A is not equal to matrix B");
    }
}