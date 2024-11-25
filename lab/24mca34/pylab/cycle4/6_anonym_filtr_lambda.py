
num = int(input("Enter the number of terms : "))
my_list = list(range(1, num+1))
multiples = list(filter(lambda x: x % 3 == 0, my_list))
print(f"Multiples of 3 : {multiples}")

