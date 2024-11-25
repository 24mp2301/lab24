def add_numbers(*args):
        """
                Adds a variable number of integer arguments.
                parameters:
                        *args:A variable length list of Integers to be added.
                returns:
                        int:the sum of all the integers passed as argumens.
        """
        if not all(isinstance(arg,int)for arg in args):
                raise valueError("All arguments must be integers!!")
        return sum(args)

print("sum of 1,2,3:",add_numbers(1,2,3))
print("sum of 10,20,30,40:",add_numbers(10,20,30,40))

