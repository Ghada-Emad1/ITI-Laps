package pkg1;
import javax.swing.JFrame;

public class TimeJFrame {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setTitle("Time and Date");
        MyPanel pn = new MyPanel();
        f.setContentPane(pn);
        f.setSize(900, 400);
        f.setVisible(true);
    }
}
