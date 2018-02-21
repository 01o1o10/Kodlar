class ogrenci:
	def derscalis(self):
			print("Ogrenci su anda ders calisiyor")
class calisan:
	def calis(self):
		print("Personel su anda calisiyor")

class yazilimci(ogrenci, calisan):
	pass

yazilimci = yazilimci()
yazilimci.derscalis()
yazilimci.calis()

input()