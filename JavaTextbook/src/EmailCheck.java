import java.util.Scanner;

class EmailAddressException extends Exception
{
	EmailAddressException(String str)
	{
		super(str);
	}
}

public class EmailCheck {

	public static void check(String str) throws EmailAddressException
	{
		String emailreg = "^[\\w-]+@([\\w- ]+\\.)+[\\w-]+$";
		Boolean b = str.matches(emailreg);
		if (b==false) throw new EmailAddressException("Dia chi email khong hop le");
	}
	public static void main(String[] args) {
		try
		{
			Scanner kb = new Scanner(System.in);
			System.out.print("Nhap dia chi email: ");
			String email = kb.nextLine();
			check(email);
		}
		catch(EmailAddressException e)
		{
			System.out.println(e.getMessage());
		}
	}

}