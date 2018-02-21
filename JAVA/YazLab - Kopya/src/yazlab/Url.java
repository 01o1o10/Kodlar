/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package yazlab;

import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

/**
 *
 * @author ILYAS MAMMADOV
 */
public class Url implements Runnable{
    Document doc;
    Kelime[] kelimeler = new Kelime[10];
    Link anaLink = new Link();
    
    Url(int id, Link anaLink, Kelime[] kelimeler){
        this.anaLink = anaLink;
        this.kelimeler = kelimeler;
    }
    
    @Override
    public void run(){
        boolean durum = true;
        try{
            doc = Jsoup.connect(anaLink.url).get();
        } catch (IOException e){
            durum = false;
        }
        
        if(durum == true){
            if(anaLink.derinlik <= 3){
                kelimeTara();
                System.out.println("Derinlik: " + anaLink.derinlik);
            }
            if(anaLink.derinlik <= 2){
                Elements elementler;
                elementler = doc.select("a[href]");
                altaDallan(elementler);
            }
        }
        /*if(anaLink.derinlik == 1){
            System.out.println("GIRDIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
            YazLab.urlAgaciYazdir(anaLink);
            System.out.println("ÇIKTIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
        }*/
    }
    
    private void altaDallan(Elements elementler){
        ExecutorService executorService = Executors.newFixedThreadPool(100);
        int i = 0;
        String url;
        for(Element link: elementler){
            url = link.attr("href");
            if(url.contains("http")){
                anaLink.altLinkler[i] = new Link(url, kelimeler, anaLink.derinlik+1);
                i++;
            }
        }
        
        i = 0;
        Url nesne;
        for(Link link: anaLink.altLinkler){
            nesne = new Url(i, anaLink.altLinkler[i], kelimeler);
            executorService.submit(nesne);
            i++;
        }
        
        executorService.shutdown();

        try {
            executorService.awaitTermination(1, TimeUnit.DAYS);
        } catch (InterruptedException e) {}
        System.out.println("Tümmm görevler bitti. Derinlik: " + anaLink.derinlik);
    }
    
    private void kelimeTara(){
        int toplam = 0;
        String veri = doc.text();
        System.out.println("URL - " + anaLink.url);
        for(Kelime kelime: anaLink.kelimeler){
            for(int pos = 0;pos != -1;){
                pos = veri.indexOf(kelime.kelime, pos+1);
                toplam++;
            }
            toplam--;
            kelime.frekans = toplam;
            System.out.println(kelime.kelime + ": " + kelime.frekans);
        }
        puanlama();
    }
    
    private void puanlama(){
        int toplam = 0;
        for(Kelime kelime: anaLink.kelimeler){
            toplam += kelime.frekans;
        }
        anaLink.puan = Math.round(toplam/anaLink.kelimeler.length);
        System.out.println("Puan: " + anaLink.puan);
    }
}
