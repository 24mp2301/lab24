def factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        fact = 1
        for i in range(2, num + 1):
            fact *= i
        return fact


def sum_series(n):
    total_sum = 0
    for i in range(1, n + 1):
        term = (i ** i) / factorial(i)  
        total_sum += term
    return total_sum


n = int(input("Enter the value of n: "))
result = sum_series(n)
print(f"The sum of the series up to the {n}th term is: {result}")
