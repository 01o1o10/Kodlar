$(document).ready(function(){
	$(".alt-dropdown-content").children().click(function(){
		var tablo_ismi = $(this).attr("value");
		$.post("../tablo_ismi_gonder.php",{bilgi: tablo_ismi},function(){
			window.location = "urunler.html";
		});
	});
});