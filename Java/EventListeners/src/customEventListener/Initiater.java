package customEventListener;

import java.util.ArrayList;
import java.util.List;

public class Initiater {

    private List<HelloListener> listeners = new ArrayList<HelloListener>();

    public void addListener(HelloListener toAdd){
        listeners.add(toAdd);
    }

    public void sayHello(){
        System.out.println("Hello");

        for(HelloListener h1 : listeners){
            h1.someoneSaidHello();
        }

    }
}
