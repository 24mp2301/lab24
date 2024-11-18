def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


def nth_prime(n):
    count = 0
    num = 2  
    while count < n:
        if is_prime(num):
            count += 1
        num += 1
    return num - 1

n = int(input("Enter the value of n: "))
print(f"The {n}th prime number is: {nth_prime(n)}")
