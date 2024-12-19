class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self):
        return self.length * self.breadth

    def perimeter(self):
        return 2 * (self.length + self.breadth)

    def __lt__(self, other):
        """Compare if this rectangle's area is less than another rectangle's area."""
        return self.area() < other.area()

    def __eq__(self, other):
        """Check if this rectangle's area is equal to another rectangle's area."""
        return self.area() == other.area()

    def __gt__(self, other):
        """Compare if this rectangle's area is greater than another rectangle's area."""
        return self.area() > other.area()


def main():

    length1 = float(input("Enter the length of the first rectangle: "))
    breadth1 = float(input("Enter the breadth of the first rectangle: "))
    rect1 = Rectangle(length1, breadth1)

    length2 = float(input("Enter the length of the second rectangle: "))
    breadth2 = float(input("Enter the breadth of the second rectangle: "))
    rect2 = Rectangle(length2, breadth2)


    print(f"Rectangle 1 - Area: {rect1.area()}, Perimeter: {rect1.perimeter()}")
    print(f"Rectangle 2 - Area: {rect2.area()}, Perimeter: {rect2.perimeter()}")

    if rect1 > rect2:
        print("The first rectangle has a larger area.")
    elif rect1 < rect2:
        print("The second rectangle has a larger area.")
    else:
        print("Both rectangles have the same area.")


if __name__ == "__main__":
    main()
