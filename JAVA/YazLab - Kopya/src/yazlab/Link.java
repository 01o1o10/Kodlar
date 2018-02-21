/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package yazlab;

/**
 *
 * @author ILYAS MAMMADOV
 */
public class Link {
    int derinlik;
    String url;
    int puan;
    Kelime[] kelimeler = new Kelime[5];
    Link[] altLinkler = new Link[1000];
    
    Link(){
        
    }
    
    Link(int derinlik){
        this.derinlik = derinlik;
    }
    
    Link(String url, Kelime[] kelimeler, int derinlik){
        this.url = url;
        this.kelimeler = kelimeler;
        this.derinlik = derinlik;
    }
}
