import sqlite3
baglanti = sqlite3.connect("ornek.db")
c = baglanti.cursor()

def sorgu():
	while(1):
		query = input(">>>")
		if(query != '*'):
			c.execute(query)
			baglanti.commit()
		else:
			break
		
def sorguyazdir():
	print()
	for row in c.execute("SELECT * FROM ogrenci"):
		print(row)

def ogrenciekle():
	isim = input("\nOgrenci ismi giriniz: ")
	soyisim = input("Ogrenci Soyismi giriniz: ")
	
	query = "INSERT INTO ogrenci VALUES ('" + isim + "', '" + soyisim + "')"
	
	c.execute(query)
	baglanti.commit()
		
while(1):		
	print("\n********MENU********")
	print("[1] - Sorgu")
	print("[2] - Sorgu Yazdir")
	print("[3] - Ogrenci Ekle")
	print("[0] - Programi Sonlandir")
	secim = int(input("\nSecim: "))
	if(secim == 1):
		sorgu()
	elif(secim == 2):
		sorguyazdir()
	elif(secim == 3):
		ogrenciekle()
	elif(secim == 0):
		baglanti.close()
		break

input()