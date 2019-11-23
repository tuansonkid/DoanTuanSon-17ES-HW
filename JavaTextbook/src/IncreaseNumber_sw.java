import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class IncreaseNumber_sw extends JFrame implements ActionListener {
	JButton bt;
	JTextField tf;
	int counter=0;
	public IncreaseNumber_sw() {
		bt = new JButton("increase");
		bt.addActionListener(this);
		
		tf = new JTextField("0");
		
		Container cont = this.getContentPane();
		cont.setLayout(new FlowLayout());
		cont.add(bt);
		cont.add(tf);
		pack();
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent event) {
		counter++;
		tf.setText(String.valueOf(counter));
	}
	
	public static void main(String[] args) {
		new IncreaseNumber_sw();
	}
}