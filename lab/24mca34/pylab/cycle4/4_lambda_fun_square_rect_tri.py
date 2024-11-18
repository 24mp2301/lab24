area_of_square = lambda side: side * side


area_of_rectangle = lambda length, width: length * width


area_of_triangle = lambda base, height: 0.5 * base * height


side = 5
length = 10
width = 4
base = 6
height = 3

print(f"Area of square: {area_of_square(side)}")
print(f"Area of rectangle: {area_of_rectangle(length, width)}")
print(f"Area of triangle: {area_of_triangle(base, height)}")
