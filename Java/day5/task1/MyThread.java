package pkg1;
import java.util.logging.Level;
import java.util.logging.Logger;
public class MyThread extends Thread {
    MyPanel panel;
    public MyThread(MyPanel panel) {
        this.panel = panel;
    }

    @Override
    public void run() {
        while (true) {
            try {
                panel.refreshPanel();
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                Logger.getLogger(MyThread.class.getName()).log(Level.SEVERE, null, e);
            }
        }
    }
}