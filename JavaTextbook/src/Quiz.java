import java.awt.*;
import java.awt.event.*;

public class Quiz extends Frame {
	Checkbox chkbook1 =new Checkbox("java.awt", false);
	Checkbox chkbook2 =new Checkbox("java.lang", false);
	Checkbox chkbook3 =new Checkbox("java.swing", false);
	Checkbox chkbook4 =new Checkbox("java.util", false);

	public Quiz(String title) {
		super(title);
		setLayout(new GridLayout(5, 1));
		add(new Label("Lop Frame thuoc goi nao?"));
		add(chkbook1);
		add(chkbook2);
		add(chkbook3);
		add(chkbook4);
		addWindowListener (new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				setVisible(false);
				System.exit(0);
			}
		});
	}
	
	public static void main(String[] args) {
		Quiz objQuiz = new Quiz("Online Quiz");
		objQuiz.setSize(550, 550);
		objQuiz.setVisible(true);
	}
}