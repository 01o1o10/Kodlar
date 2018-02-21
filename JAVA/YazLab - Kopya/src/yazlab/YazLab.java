/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package yazlab;


import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author ILYAS MAMMADOV
 */
public class YazLab {
    
    static Link agac = new Link(0);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        int kelimeSayisi;
        System.out.print("Aranacak kelime sayisini giriniz: ");
        kelimeSayisi = scan.nextInt();
        Kelime[] kelimeler = new Kelime[kelimeSayisi]; 
        
        //kelimelerin alinmasi
        for(int i = 0; i < kelimeSayisi; i++){
            kelimeler[i] = new Kelime();
            System.out.print("Kelime: ");
            kelimeler[i].kelime = scan.next();
        }
        
        int linkSayisi;
        System.out.print("Aranacak link sayisini giriniz: ");
        linkSayisi = scan.nextInt();
        ExecutorService executorService = Executors.newFixedThreadPool(linkSayisi);
        
        
        String url;
        for(int i = 0; i < linkSayisi; i++){
            System.out.print("Link: ");
            url = scan.next();
            agac.altLinkler[i] = new Link(url, kelimeler, 1);
        }
        
        System.out.println(">>>>>>>>>>>>>>>>>>>>YAZIYOR YAZIYOOOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
        urlAgaciYazdir(agac);
        System.out.println(">>>>>>>>>>>>>>>>>>>>YAZIYOR YAZIYOOOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
        
        
        int i = 0;
        Url nesne;
        for(Link link: agac.altLinkler){
            nesne = new Url(i, agac.altLinkler[i], kelimeler);
            executorService.submit(nesne);
            i++;
        }
        
        executorService.shutdown();
        
        System.out.println("Tüm linkler için statik nesne oluşturuldu ve");
        System.out.println("tüm görevler eklendi.");
        
        try {
            executorService.awaitTermination(2, TimeUnit.MINUTES);
        } catch (InterruptedException e) {}
        
        System.out.println(">>>>>>>>>>>>>>>>>>>>YAZIYOR YAZIYOOOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
        urlAgaciYazdir(agac);
        System.out.println(">>>>>>>>>>>>>>>>>>>>YAZIYOR YAZIYOOOR<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
    }
    
    public static void urlAgaciYazdir(Link dugum){
        System.out.println(dugum.url);
        System.out.println("Derinlik: " + dugum.derinlik);
        System.out.println("Puan: " + dugum.puan);
        for(Kelime kelime: dugum.kelimeler){
            if(kelime != null){
                System.out.println(kelime.kelime + ": " + kelime.frekans);
            }
        }
        for(Link link: dugum.altLinkler){
            if(link != null){
                urlAgaciYazdir(link);
            }
        }
        System.out.println("");
    }
}
