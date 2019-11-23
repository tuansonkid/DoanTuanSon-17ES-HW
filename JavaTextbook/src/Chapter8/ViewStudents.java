package Chapter8;

import java.sql.*;
import java.util.*;
import javax.swing.*;

public class ViewStudents {

	public static void main(String[] args) {
		Vector vData = null, vTitle = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/studentmanagement","root","");
			Statement stm = conn.createStatement();
			ResultSet rst = stm.executeQuery("Select * from students");
			ResultSetMetaData rstmeta = rst.getMetaData();
			int num_column = rstmeta.getColumnCount();
			
			vTitle = new Vector(num_column);
			for (int i=1;i<=num_column;i++)
				vTitle.add(rstmeta.getColumnLabel(i));
			
			vData = new Vector(10,10);
			while (rst.next()) {
				Vector row = new Vector(num_column);
				for (int i=1;i<=num_column;i++)
					row.add(rst.getString(i));
				vData.add(row);
			}
			rst.close();
			stm.close();
			conn.close();
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
		}
		JScrollPane tableResult = new JScrollPane(new JTable(vData, vTitle));
		JFrame f = new JFrame();
		f.setSize(600,480);
		f.setContentPane(tableResult);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.show();
	}

}
