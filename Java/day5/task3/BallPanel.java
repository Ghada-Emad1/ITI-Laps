package pkg3;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class BallPanel extends JPanel implements Runnable{
    int x=0;
    int y=100;
    int xSpeed=5;
    int ySpeed=5;
    public BallPanel(){
        this.setBackground(Color.black);
        Thread thr=new Thread(this);
        thr.start();

    }
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.setColor(Color.red);
        g.fillOval(x, y, 30, 30);

    }
    @Override 

    public void run() {
        while (true) {
            x+=xSpeed;
            y+=ySpeed;
            if (x>=getWidth()||x<= 0) {
                xSpeed=-xSpeed;
                
            }
            if (y+30>=getHeight()||y<=0) {
                ySpeed= -ySpeed; 
            }
            repaint();

            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}