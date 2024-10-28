number = input("Enter a number: ")

is_palindrome = True
length = len(number)


for i in range(length // 2):
    if number[i] != number[length - 1 - i]:
        is_palindrome = False
        break


if is_palindrome:
    print(f"{number} is a palindromic number.")
else:
    print(f"{number} is not a palindromic number.")
