<?php
//email gönderimi için gerekli olan dosyaları dahil ediyoruz.
include 'PHPMailer.php';
include 'SMTP.php';
include 'POP3.php';

//İletişim formumuzdan gelen bilgileri alıyoruz.
$adisoyadi=$_POST['adisoyadi'];
$telefon=$_POST['telefon'];
$eposta=$_POST['eposta'];
$mesaj=$_POST['mesaj'];
 
$mail = new PHPMailer(); //ilgili PHPMailer class'ımızdan bir nesne türetiyoruz.
$mail->IsSMTP();
$mail->SMTPAuth = true; 
$mail->Host = 'smtp.gmail.com'; //SMTP için kullanılacak sunucu adresi
$mail->Port = 587; //TLS protokolünün kullanacağı port numarası
$mail->SMTPSecure = 'tls'; //kullanacağımız güvenlik protokolü SSL veya TLS olabilir.
$mail->Username = 'by.computer.engineer@gmail.com'; //Email gönderecek adres
$mail->Password = 'AZNp5415893'; ////Email gönderecek adresin şifresi
$mail->SetFrom($mail->Username, 'Ilyas Mammadov');
$mail->AddAddress('Gidecek email adresi', '
'); //Bu emaili gideceği e-posta adresi
$mail->CharSet = 'UTF-8'; //Karakterlerin düzgün görünmesi için utf-8 ekliyoruz.
$mail->Subject ="Web sitesinin iletişim bölümünden mesaj var"; //emailimizin konusu

//email içeriğimiz
$icerik = "Gönderen:".$adisoyadi.
 " Telefon:".$telefon.
 " E-posta:".$eposta.
 " Mesaj:".$mesaj ;
 
$mail->MsgHTML($icerik);

//Artık emailimizi gönderiyoruz, yukarıdaki bilgilerde bir hata varsa bu satırda hata verecektir.
if($mail->Send()) {
     //E-posta gönderildi
     echo "Email başarıyla gönderildi";
} else {
    // Bir hata oluştu, hata mesajı yazdırıyoruz
    echo $mail->ErrorInfo;
}
 
?>