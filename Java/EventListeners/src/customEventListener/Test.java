package customEventListener;

public class Test {

    public static void main(String args[]){


        //source of action
        Initiater initiater = new Initiater();

        //action listener
        Responder responder = new Responder();

        //variant with pre-declared listener
        //someoneSaidHello method is implemented in Responder class
        initiater.addListener(responder);

        //variant with abstract class
        initiater.addListener(new HelloListener(){

            @Override
            public void someoneSaidHello() {
                System.out.println("Someone said hello ;). Abstract class implementation.");
            }
        });



        initiater.sayHello();

    }
}
