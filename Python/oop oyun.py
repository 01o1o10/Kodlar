import random

class Dusman:
	
	def __init__(self,isim = "Dusman",kalan_can = 100,saldiri_gucu = 5,mermi_sayisi = 100):
		self.isim = isim
		self.kalan_can = kalan_can
		self.saldiri_gucu = saldiri_gucu
		self.mermi_sayisi = mermi_sayisi
	
	def saldir(self):
		print(self.isim + " saldiriyor")
		harcanan_mermi = random.randrange(0,10)
		print(str(harcanan_mermi) + " mermi harcandi")
		self.mermi_sayisi -= harcanan_mermi
		
		return(harcanan_mermi, self.saldiri_gucu)
		
	def saldiriyaugra(self, harcanan_mermi,saldiri_gucu):
		print(self.isim + ": Vuruldum...")
		print(str(harcanan_mermi * saldiri_gucu) + " canim gitti.")
		self.kalan_can -=(harcanan_mermi * saldiri_gucu)
		
	def mermi_bitti_mi(self):
		if(self.mermi_sayisi <= 0):
			print(self.isim + " konusuyor: Mermim bitti, oyundan cikiyorum.")
			return True
		return False
		
	def hayatta_mi(self):
		if(self.kalan_can <= 0):
			print(self.isim + ": oluyorummm...")
		else:
			print(self.isim + " - Kalan Can: " + str(self.kalan_can))
		
	def print(self):
		print()
		print("Isim: " + self.isim)
		print("Kalan Can: " + str(self.kalan_can))
		print("Saldiri Gucu: " + str(self.saldiri_gucu))
		print("Mermi Sayisi: " + str(self.mermi_sayisi))

dusmanlar = []

i = 0
while(i < 10):
	rasgelecan = random.randrange(200, 500)
	rasgelesaldirigucu = random.randrange(10,20)
	rasgelemermi = random.randrange(10,70)
	yenidusman = Dusman("Dusman" + str(i+1), rasgelecan, rasgelesaldirigucu, rasgelemermi)
	dusmanlar.append(yenidusman)
	
	i += 1
	

i = 0 
while(i < 3):
	randomdusman1 = random.randrange(0,10)
	randomdusman2 = random.randrange(0,10)
	
	donendeger = dusmanlar[randomdusman1].saldir()
	dusmanlar[randomdusman2].saldiriyaugra(donendeger[0], donendeger[1])
	
	i += 1
	
	print("***************Round Bitti*************")
	

input()