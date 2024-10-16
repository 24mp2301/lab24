

import math
a=float(input("Enter a:"))
b=float(input("Enter b:"))
c=float(input("Enter c:"))
dis=b**2-4*a*c
if dis>0:
        root1=(-b+math.sqrt(dis))/(2*a)
        root2=(-b-math.sqrt(dis))/(2*a)
        print(f"Roots are real and distinct: {root1} and {root2}")

elif dis==0:
        root=-b/(2*a)
        print(f"Root is real and equal: {root}")
else:
        real_part=-b/(2*a)
        imag_part=math.sqrt(-dis)/(2*a)
        print(f"Roots are complex: {real_part}+{imag_part}i and {real_part}-{imag_part}i")

