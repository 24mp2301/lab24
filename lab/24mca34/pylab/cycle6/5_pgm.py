class Time:
    def __init__(self, hour, minute, second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def __add__(self, other):

        total_seconds = self.__second + other.__second
        total_minutes = self.__minute + other.__minute + (total_seconds // 60)
        total_hours = self.__hour + other.__hour + (total_minutes // 60)


        seconds = total_seconds % 60
        minutes = total_minutes % 60
        hours = total_hours % 24

        return Time(hours, minutes, seconds)

    def display(self):
        print(f"{self.__hour:02}:{self.__minute:02}:{self.__second:02}")


def main():

    print("Enter the first time:")
    hour1 = int(input("Hour: "))
    minute1 = int(input("Minute: "))
    second1 = int(input("Second: "))
    time1 = Time(hour1, minute1, second1)

    print("Enter the second time:")
    hour2 = int(input("Hour: "))
    minute2 = int(input("Minute: "))
    second2 = int(input("Second: "))
    time2 = Time(hour2, minute2, second2)


    total_time = time1 + time2

    print("The sum of the two times is:")
    total_time.display()


if __name__ == "__main__":
    main()
