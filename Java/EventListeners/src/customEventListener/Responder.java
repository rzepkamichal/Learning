package customEventListener;

public class Responder implements HelloListener {

    @Override
    public void someoneSaidHello() {
        System.out.println("someone said hello xd. Responder class implementation");
    }
}
