number = int(input("Enter a number: "))
factorial = 1


if number < 0:
    print("Factorial is not defined for negative numbers.")
elif number == 0:
    print("The factorial of 0 is 1.")
else:
    for i in range(1, number + 1):
        factorial *= i
    print("The factorial of", number, "is", factorial)
