list1_input = input("Enter the first list of integers (comma seperated):")
list1 = [int(num.strip()) for num in list1_input.split(",")]

list2_input = input("Enter the second list of integers (comma seperated):")
list2 = [int(num.strip()) for num in list2_input.split(",")]

same_length = len(list1) == len(list2)

same_sum = sum(list1) == sum(list1)

common_values = any(num in list2 for num in list1)

print("Are the lists of the same length?",same_length)
print("Do the lists sum to the same values?",same_sum)
print("Is there any value that occurs in both lists?", common_values)
