import java.util.Scanner;
import java.util.Vector;
import java.util.Enumeration;
import java.util.Arrays;

public class StudentManagement {

	/*Dung de chua danh sach sinh vien*/
	Vector list = new Vector();
	public StudentManagement() {
		while (true) {
			/*Hien thi menu chuong trinh*/
			System.out.println("*CHUONG TRINH QUAN LY SINH VIEN-*");
			System.out.println("*Chuc nang chinh chuong trinh-*");
			System.out.println(" 1. Nhap danh sach sinh vien   ");
			System.out.println(" 2. Xem danh sach sinh vien   ");
			System.out.println(" 3. Sap xep danh sach sinh vien tang dan diem trung binh");
			System.out.println(" 4. Tim sinh vien theo ten   ");
			System.out.println(" 5. Thoat   ");
			System.out.println(" -------------");
			
			/*Nhap mot so tu ban phim*/
			int num;
			Scanner keyboard = new Scanner(System.in);
			System.out.print(" Nhap mot so de chon chuc nang: ");
			num = keyboard.nextInt();
			
			/*Kiem tra va goi chuc nang tuong ung*/
			switch(num) {
			case 1:
				this.input();
				break;
			case 2:
				this.view();
				break;
			case 3:
				sort();
				break;
			case 4:
				search();
				break;
			case 5:
				System.out.print("---- Chuong trinh ket thuc----- ");
			return;
			}
		}
	}
	
	public void input() {
		/*Nhap so luong sinh vien cho danh sach*/
		int num;
		Scanner keyboard = new Scanner(System.in);
		System.out.print(" Nhap so luong sinh vien: ");
		num = keyboard.nextInt();
		
		/*Nhap thong tin cho moi sinh vien*/
		for(int i=0; i<=num; i++) {
			System.out.println(" Nhap thong tin cho sinh vien thu: "+i);
			System.out.print(" ID: ");
			int id = Integer.parseInt(keyboard.next());
			
			keyboard.nextLine(); //Xoa bo dem
			System.out.print(" Ten: ");
			String name = keyboard.nextLine();
			
			System.out.print(" Diem trung binh: ");
			float aver = keyboard.nextFloat();
			
			/*Sau khi nhap thong tin, tao doi tuong sinh vien*/
			Student st = new Student(id, name, aver);
			
			/*Luu doi tuong sinh vien vao danh sach*/
			list.add(st);
		}
		System.out.println("\n--------\n");
	}
	
	/*Xem danh sach sinh vien*/
	public void view() {
		/*Hien thi danh sach sinh vien*/
		System.out.println(" Thong tin danh sach sinh vien:");
		
		/*Lay sinh vien tu danh sach (Vector) va Luu tru o vEnum*/
		Enumeration vEnum = list.elements();
		
		/*Duyet tung phan tu cua vEnum*/
		int i=1;
		
		/*Chua het phan tu*/
		while(vEnum.hasMoreElements()) {
			/*Lay phan tu tu vEnum ep lai kieu Student*/
			Student sts = (Student)vEnum.nextElement();
			
			/*Hien thi thong tin sinh vien*/
			System.out.println("   "+i+". ID="+sts.getId()+", Ten="+sts.getName()+", Diem trung binh="+sts.getAver());
			i++;
		}
		System.out.println("\n--------\n");
	}
	
	/*Sap xep danh sach theo chieu tang dan cua diem trung binh su dung ham sort cua lop Arrays*/
	public void sort() {
		/*Do du lieu tu Vector vao mang de goi ham sort sap xep mang*/
		Student[] sts = new Student[list.size()];
		int index=0;
		
		Enumeration vEnum = list.elements();
		while(vEnum.hasMoreElements()) {
			sts[index] = (Student)vEnum.nextElement();
			index++;
		}
		
		/*Sap xep mang*/
		Arrays.sort(sts);
		System.out.println("\n--Danh sach sinh vien sau khi sap xep--");
		for(index=0; index < sts.length; index++) {
			/*Hien thi thong tin sinh vien sau khi sap xep*/
			System.out.println("   "+(index+1)+".ID="+sts[index].getId()+", Ten="+sts[index].getName()+", Diem trung binh="+sts[index].getAver());
		}
		System.out.println("\n--------\n");
	}
	
	/*Tim kiem sinh vien theo ten*/
	public void search() {
		/*Nhap ten sinh vien can tim kiem*/
		Scanner keyboard = new Scanner(System.in);
		System.out.print(" Nhap ten sinh vien can tim: ");
		String name = keyboard.nextLine();
		
		/*Duyet tung phan tu cua mang de so sanh ten tim kiem*/
		Enumeration vEnum = list.elements();
		System.out.println("\n--Thong tin tim kiem duoc--");
		while(vEnum.hasMoreElements()) {
			Student sts = (Student)vEnum.nextElement();
			/*Neu ten sinh vien chua chuoi nhap vao thi hien thi thong tin doi tuong sinh vien*/
			if(sts.getName().indexOf(name)!=-1)
				System.out.println("ID="+sts.getId()+", Ten="+sts.getName()+", Diem trung binh="+sts.getAver());
		}
		System.out.println("\n--------\n");
	}
	
	public static void main(String[] args) {
		/*Khoi tao chuong trinh*/
		new StudentManagement();
	}
}

/*Xay dung lop Student hien thuc interface Comparable, dinh nghia cu the ham compareTo de phuc vu sap xep*/
class Student implements Comparable{
	private int id;
	private String name;
	private float aver;
	
	/*Ham khoi tao mac dinh*/
	public Student() {
		name = new String("");
		id=0;
		aver=0;
	}
	
	/*Ham khoi tao 3 doi so*/
	public Student(int i, String n, float a) {
		id=i;
		name=n;
		aver=a;
	}
	
	/*Ham lay gia tri name*/
	public String getName() {
		return name;
	}
	
	/*Ham lay gia tri id*/
	public int getId() {
		return id;
	}
	
	/*Ham lay gia tri aver*/
	public float getAver() {
		return aver;
	}
	
	/*Ham so sanh 2 doi tuong Student phuc vu sap xep*/
	public int compareTo(Object other) {
		Student otherRect = (Student)other;
		return (int)(this.aver-otherRect.aver);
	}
}