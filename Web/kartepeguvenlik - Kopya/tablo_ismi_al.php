<?php
	$dosya = fopen("bilgi.txt","r");
	$tablo = fgets($dosya);
	fclose($dosya);
	echo $tablo;
?>