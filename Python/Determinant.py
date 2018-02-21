def determinant(matris, n):
	if(n == 0):
		return "Herhangi birsey girmediniz!"
	elif(n == 1):
		determ = matris[0][0]
	elif(n == 2):
		determ = matris[0][0]*matris[1][1] - matris[0][1]*matris[1][0]
	else:
		determ = 0
		for k in range(0, n):
			a = []
			for i in range(1, n):
				if(k < n-1):
					mat = matris[i][0:k]+ matris[i][(k+1):n]
				else:
					mat = matris[i][0:k]
				a += [mat]
			print(a)
			print(determinant(a, n-1))
			determ += (matris[0][k] * ((-1)**(k)) * determinant(a, n-1))
			print(determ)
	return determ
