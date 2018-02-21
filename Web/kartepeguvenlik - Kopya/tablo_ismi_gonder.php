<?php
	$tablo = $_POST['bilgi'];
	$dosya = fopen("bilgi.txt","w");
	fwrite($dosya, $tablo);
	fclose($dosya);
?>