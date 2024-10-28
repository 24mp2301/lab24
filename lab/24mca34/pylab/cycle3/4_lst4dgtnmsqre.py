even_digit_squares = []

for num in range(32, 100):  
    square = num * num
    if 1000 <= square <= 9999:
        square_str = str(square)
        if (square_str[0] in "02468" and
            square_str[1] in "02468" and
            square_str[2] in "02468" and
            square_str[3] in "02468"):
            even_digit_squares.append(square)

print("Four-digit numbers that are perfect squares with all even digits:", even_digit_squares)
