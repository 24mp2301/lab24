input_numbers = input("enter a list of integers(comma seperated):")

numbers = [int(num.strip()) for num in input_numbers.split(",")]

result = ['over' if num > 100 else num for num in numbers]

print("resulting list",result)
