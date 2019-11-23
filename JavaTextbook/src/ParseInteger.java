import java.util.*;

public class ParseInteger {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try 
		{
			Scanner kb = new Scanner(System.in);
			System.out.print("Nhap chuoi so nguyen: ");
			String str = kb.nextLine();
			int num = Integer.parseInt(str);
			System.out.println(num);
		}
		catch(NumberFormatException e)
		{
			System.out.println("Chuoi nhap vao khong dung dinh dang");
		}
	}
}