def factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        fact = 1
        for i in range(2, num + 1):
            fact *= i
        return fact


def permutations(n, r):
    return factorial(n) // factorial(n - r)


def combinations(n, r):
    return factorial(n) // (factorial(r) * factorial(n - r))


n = int(input("Enter the value of n: "))
r = int(input("Enter the value of r: "))

p_result = permutations(n, r)
c_result = combinations(n, r)

print(f"The number of permutations p({n}, {r}) is: {p_result}")
print(f"The number of combinations c({n}, {r}) is: {c_result}")
