from abc import ABC, abstractmethod

class Polygon(ABC):
    @abstractmethod
    def get_dimensions(self):
        pass

    @abstractmethod
    def calculate_area(self):
        pass


class Rectangle(Polygon):
    def __init__(self):
        self.length = 0
        self.breadth = 0

    def get_dimensions(self):
        self.length = float(input("Enter the length of the rectangle: "))
        self.breadth = float(input("Enter the breadth of the rectangle: "))

    def calculate_area(self):
        return self.length * self.breadth


class Triangle(Polygon):
    def __init__(self):
        self.base = 0
        self.height = 0

    def get_dimensions(self):
        self.base = float(input("Enter the base of the triangle: "))
        self.height = float(input("Enter the height of the triangle: "))

    def calculate_area(self):
        return 0.5 * self.base * self.height


def main():
    print("Choose a polygon:")
    print("1. Rectangle")
    print("2. Triangle")
    choice = int(input("Enter your choice (1 or 2): "))

    if choice == 1:
        polygon = Rectangle()
    elif choice == 2:
        polygon = Triangle()
    else:
        print("Invalid choice!")
        return

    polygon.get_dimensions()
    area = polygon.calculate_area()
    print(f"The area of the selected polygon is: {area}")


if __name__ == "__main__":
    main()
