N = int(input("Enter the number of steps: "))
for i in range(1, N + 1):
    
    row = []
    for j in range(1, i + 1):
        
        value = j * i
        row.append(str(value))  
    print(" ".join(row))
