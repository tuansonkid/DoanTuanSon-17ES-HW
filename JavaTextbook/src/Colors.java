import java.awt.*;
import java.awt.event.*;

public class Colors extends Frame implements ItemListener{
	Choice clrs = new Choice();
	public Colors(String title) {
		super(title);
		setLayout(new FlowLayout());
		clrs.addItem("White");
		clrs.addItem("Black");
		clrs.addItem("Red");
		clrs.addItem("Yellow");
		clrs.addItem("Pink");
		add(clrs);
		clrs.addItemListener(this);
		this.setBackground(Color.white);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				setVisible(false);
				System.exit(0);
			}
		});
	}
	
	public void itemStateChanged(ItemEvent e) {
		int index = clrs.getSelectedIndex();
		if (index==0) this.setBackground(Color.white);
		else if (index==1) this.setBackground(Color.black);
		else if (index==2) this.setBackground(Color.red);
		else if (index==3) this.setBackground(Color.yellow);
		else this.setBackground(Color.pink);
	}
	
	public static void main(String[] args) {
		Colors objColors = new Colors("Choice Demo");
		objColors.setVisible(true);
		objColors.setSize(400, 400);
	}
}