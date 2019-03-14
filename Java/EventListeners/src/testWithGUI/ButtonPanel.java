package testWithGUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonPanel extends JPanel implements ActionListener {

    public static final int HEIGHT = 100;
    public static final int WIDTH = 300;
    private JButton redB, greenB, blueB;

    public ButtonPanel(){
        greenB = new JButton("green");
        redB = new JButton("red");
        blueB = new JButton("blue");

        greenB.addActionListener(this);
        redB.addActionListener(this);
        blueB.addActionListener(this);

        setLayout(new FlowLayout());
        setPreferredSize(new Dimension(WIDTH,HEIGHT));

        add(greenB);
        add(redB);
        add(blueB);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        Object source = e.getSource();

        if(source == greenB)
            setBackground(Color.GREEN);
        else if(source == redB)
            setBackground(Color.RED);
        else if(source == blueB)
            setBackground(Color.BLUE);
    }
}
