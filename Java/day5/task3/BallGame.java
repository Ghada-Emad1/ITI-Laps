package pkg3;
import javax.swing.JFrame;
import javax.swing.JPanel;
public class BallGame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Moving Ball");
        BallPanel panel = new BallPanel();
        frame.setContentPane(panel);
        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
