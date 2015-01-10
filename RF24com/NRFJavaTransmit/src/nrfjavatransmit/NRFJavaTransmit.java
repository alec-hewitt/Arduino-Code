
package nrfjavatransmit;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

/**
 * @author Alec Hewitt
 * ahewitt0000@gmail.com
 * www.ahewdev.com
 */

public class NRFJavaTransmit {

    public static void main(String[] args) {
        //setup transmit pipeline then send data
        
        //new output stream object
        PipedOutputStream output = new PipedOutputStream();
        
        //tranceiver input
        PipedInputStream input = new PipedInputStream();
        
        try{
            //connect to receiver input
            output.connect(input);
        }
        catch(IOException e){
            System.out.println("cannot connect");
        }
        
    }
    
}
