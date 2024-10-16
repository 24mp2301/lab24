string = input("enter your string:")
if string[-3:]=="ing":
	print(string[:-3]+"ly")
else:
	print(string+"ing")
