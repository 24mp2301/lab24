input_words = input("Enter a list of words(seperated by spaces):")

words = input_words.split()

if words:
	longest_word_length = max(len(word) for word in words)

else:
	longest_word_length = 0

print("Length of the longestvword:",longest_word_length)
