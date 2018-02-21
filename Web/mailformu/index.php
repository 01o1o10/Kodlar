<!DOCTYPE html>
<html lang="en">
  <head>
<meta charset="utf-8"> 
 <title>Kullanıcı Girişi</title>
</head>
<body>
<form action="mailgonder.php" method="POST">
<table align="center">
<tr>
<td>Adı Soyadı (*)</td>
<td><input type="text" name="adisoyadi"></td>
</tr>
<tr>
<td>Telefon (*)</td>
<td><input type="text" name="telefon"></td>
</tr>
<tr>
<td>E-posta</td>
<td>
    <input type="text" name="eposta">
</td>
</tr>
<tr>
<td>Mesaj</td>
<td>
      <textarea name="mesaj" cols="30" rows="10"></textarea>
</td>
</tr>
<tr>
 
<td colspan="2" align="right">
    <input type="submit" value="Gönder"></td>
</tr>
 
</table>
</form>
 
</body>
</html>
