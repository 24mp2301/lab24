n_terms = int(input("Enter the number of terms: "))

# First two terms of the Fibonacci series
a, b = 0, 1


if n_terms <= 0:
    print("Please enter a positive integer.")
elif n_terms == 1:
    print("Fibonacci series:", a)
else:
    print("Fibonacci series:", end=" ")
    for _ in range(n_terms):
        print(a, end=" ")
        a, b = b, a + b
