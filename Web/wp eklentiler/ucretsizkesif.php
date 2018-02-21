<?php

	include "PHPMailer.php";
	include "POP3.php";
	include "SMTP.php";

	$ad_soyad = $_POST['ad-soyad'];
	$firma = $_POST['firma'];
	$e_posta = $_POST['e-posta'];
	$telefon = $_POST['telefon'];
	$mesaj = $_POST['mesaj'];


	IsSMTP();
	$mail->SMTPDebug = 1; // hata ayiklama: 1 = hata ve mesaj, 2 = sadece mesaj
	$mail->SMTPAuth = true;
	$mail->SMTPSecure = 'tls'; // Güvenli baglanti icin ssl normal baglanti icin tls
	$mail->Host = "smtp.gmail.com"; // Mail sunucusuna ismi
	$mail->Port = 465; // Gucenli baglanti icin 465 Normal baglanti icin 587
	$mail->IsHTML(true);
	$mail->SetLanguage("tr", "phpmailer/language");
	$mail->CharSet  ="utf-8";
	$mail->Username = "by.computer.engineer@gmail.com"; // Mail adresimizin kullanicı adi
	$mail->Password = "AZNp5415893"; // Mail adresimizin sifresi
	$mail->SetFrom("by.computer.engineer@gmail.com", "Ilyas"); // Mail attigimizda gorulecek ismimiz
	$mail->AddAddress("ilyas.mammadov.96@gmail.com"); // Maili gonderecegimiz kisi yani alici
	$mail->Subject = "Mesaj Konusu"; // Konu basligi
	$mail->Body = $mesaj; // Mailin icerigi
	if(!$mail->Send()){
	    echo "Mailer Error: ".$mail->ErrorInfo;
	} else {
	    echo "Mesaj gonderildi";
	}


?>
