n = input("enter your string").lower()
s={}

for i in n:
	if i in s:
		s[i]+=1
	else:
		s[i]=1
print(s)
