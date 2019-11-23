package Chapter8;

import java.sql.*;

public class JDBCDemo {

	public static void main(String[] args) {
		try {
			/*Nap driver*/
			Class.forName("com.mysql.jdbc.Driver");
			/*Ket noi den csdl va tao doi tuong Statement*/
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/studentmanagement","root","");
			Statement sm = conn.createStatement();
			/*Them thong tin vao bang students*/
			sm.executeUpdate("Insert into students values(9, \"NVQuan\", 8, 7, 9, (8+7+9)/3)");
			sm.executeUpdate("Insert into students values(10, \"PVThuan\", 8, 5, 9, (8+5+9)/3)");
			/*Truy van thong tin tu bang students*/
			ResultSet rs = sm.executeQuery("Select * from students");
			/*Tao ResultSetMetaData de lay thong tin so cot cua ResultSet*/
			ResultSetMetaData rsm = rs.getMetaData();
			int col_num = rsm.getColumnCount();
			/*Lay ten cot cua bang students tu doi tuong rsm*/
			for (int i=1;i<col_num;i++)
				System.out.print(rsm.getColumnLabel(i)+ "\t");
			System.out.println("");
			/*Hien thi thong tin truy van duoc tu bang students*/
			while (rs.next()) {
				/*Moi hang cua ResultSet duyet cac o de lay du lieu*/
				for (int i=1;i<=col_num;i++)
					System.out.print(rs.getString(i)+ "\t");
				/*Xuong dong moi*/
				System.out.println("");
			}
		}
		catch (Exception e) {
			System.out.println(e);
		}
	}

}
