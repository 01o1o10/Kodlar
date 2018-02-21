$(document).ready(function(){
	$.post("../tablo_ismi_al.php",{},function(veri1){
		tablo_ismi = veri1;
		$.post("geturun.php", {tablo: tablo_ismi}, function(veri2){
			$(".urunler2").append(veri2);
		});
	});
});