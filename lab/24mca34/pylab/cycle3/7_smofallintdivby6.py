upper_limit = int(input("Enter the upper limit: "))
total_sum = 0


for num in range(1, upper_limit):
    if num % 6 == 0 and num % 4 != 0:
        total_sum += num

print("The sum of all integers below", upper_limit, "that are divisible by 6 but not by 4 is:", total_sum)
