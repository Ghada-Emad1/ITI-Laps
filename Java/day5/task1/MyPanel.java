package pkg1;
import java.awt.Color;
import java.awt.Graphics;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JPanel;
public class MyPanel extends JPanel {
    int x;
    String currentTime;
    public MyPanel(){
        this.setBackground(Color.BLACK);
        x=100;
        MyThread thr=new MyThread(this);
        thr.start();
    }
    void updateTime(){
        currentTime=new Date().toLocaleString();
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.setColor(Color.WHITE);
        g.drawString(currentTime, x, 100);
    }

    public void refreshPanel() {
        if(x+50>=getWidth()){
            x=0;
        }else{
            x+=50;
        }
        updateTime();
        repaint(); 
    }
}

