color_input = input("Enter colors(comma seperated):")
colors = [color.strip() for color in color_input.split(",")]

if colors:
	first_color = colors[0]
	last_color  = colors[-1]
	print("First color:",first_color)
	print("last color:",last_color)
else:
	print("No colors entered")

