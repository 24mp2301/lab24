age = int(input("enter your age: "))

rate = 0

if(age<10):
	rate=7
elif age>=10 and age<60:
	rate=10
elif age>=60:
	rate=5
else:
	print("enter a valid age!")
print(f"The ticket rate is {rate}rs.")
