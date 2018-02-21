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
public class Link {
    int id;
    Link[] altlinkler = new Link[2];
    
    Link(int id){
        this.id = id;
        if(id < 5){
            this.altlinkler[0] = new Link(id+1);
            this.altlinkler[1] = new Link(id+1);
        }
    }
}
