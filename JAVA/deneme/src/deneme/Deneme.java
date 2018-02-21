/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package deneme;

/**
 *
 * @author ILYAS MAMMADOV
 */
public class Deneme {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Link nesne = new Link(0);
        
        nesne.altlinkler[0] =new Link(1);
        nesne.altlinkler[1] =new Link(1);
        
        
    }
    
    public static void func(Link nesne){
        nesne.altlinkler[0] = new Link(2);
        nesne.altlinkler[1] = new Link(2);
    }
    
}
