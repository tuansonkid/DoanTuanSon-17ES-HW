import java.util.Scanner;

class WebAddressException extends Exception
{
	public WebAddressException(String str)
	{
		super(str);
	}
}

public class WebAddressCheck {
	public static void checkWebaddress(String s) throws WebAddressException
	{
		String numReg = "^https?://([\\w-]+\\.)+[\\w-]+(/[\\w-./?%=]*)?$";
		Boolean b = s.matches(numReg);
		if (b==false) throw new WebAddressException("Dia chi web khong hop le");
		else System.out.println("Dia chi web hop le");
	}
	public static void main(String[] args) {
		try
		{
			Scanner kb = new Scanner(System.in);
			System.out.print("Nhap dia chi web: ");
			String webadd = kb.nextLine();
			checkWebaddress(webadd);
		}
		catch(WebAddressException e)
		{
			System.out.println(e.getMessage());
		}

	}

}