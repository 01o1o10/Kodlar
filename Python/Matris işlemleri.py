import Determinant
matris = []
mat = []

m = int(input("Matrisin boyutunu giriniz: "))

for i in range(0, m):
	for j in range(0, m):
		mat += [int(input("Matrisin {}. satir {}. sutun elemanini giriniz: ".format(i,j)))]
	matris += [mat]
	mat = []
	print()
print(matris)
		
det = Determinant.determinant(matris, m)
print("Girilen matrisin determinanti {}'dir".format(det))

	




































input()