upper_limit = int(input("Enter the upper limit: "))

print("Sum of digits (prime values only) for each number in the range:")

for num in range(1, upper_limit + 1):
    
    digit_sum = 0
    temp = num
    while temp > 0:
        digit_sum += temp % 10  
        temp //= 10  

    if digit_sum <= 1:
        continue  

    is_prime = True
    for i in range(2, int(digit_sum**0.5) + 1):
        if digit_sum % i == 0:
            is_prime = False
            break


    if is_prime:
        print(f"Number: {num}, Sum of Digits: {digit_sum}")
