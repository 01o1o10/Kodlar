/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esanlamlilar;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;



/**
 *
 * @author ILYAS MAMMADOV
 */
public class Esanlamlilar {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        
        
        List<String> sonuc;
        sonuc = esanlamli("Aniden");
        sonuc.forEach((kelime) -> {
            System.out.println(kelime);
        });
        System.out.println(boslukEkle("aninda"));
        
        System.out.println(kelimeCevir(boslukEkle("ümüd")));
        
    }
    
    public static List esanlamli(String aranan) throws IOException{
        String dosyaYolu = "C:\\Users\\ILYAS MAMMADOV\\Desktop\\Çalışmalar\\Kodlar\\JAVA\\sozluk.txt";
        File dosya = new File(dosyaYolu);
        List<String> sonuc = new ArrayList<>();
        
        try{
            try (BufferedReader oku = new BufferedReader(
                    new InputStreamReader(
                            new FileInputStream(dosya), "UTF8"))) {
                String str;
                
                while ((str = oku.readLine()) != null) {
                    String[] kelime = str.split(" ");
                    int i = 0;
                    if(kelime[0].equalsIgnoreCase(aranan)){
                        sonuc.add(kelime[1]);
                        i++;
                    }
                }
            }
        }
        catch(FileNotFoundException | UnsupportedEncodingException e){
        }
        
        return sonuc;
    }
    
    public static String kelimeCevir(String kelime){
        String yeniKelime = kelime.replaceAll("ı", "i");
        yeniKelime = yeniKelime.replaceAll("ğ", "g");
        yeniKelime = yeniKelime.replaceAll("ü", "u");
        yeniKelime = yeniKelime.replaceAll("ö", "o");
        return yeniKelime;
    }
    
    public static String boslukEkle(String kelime){
        String yeniKelime = kelime.concat(" ");
        yeniKelime = " ".concat(yeniKelime);
        return yeniKelime;
    }
    
}
