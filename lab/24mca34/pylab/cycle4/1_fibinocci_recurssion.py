def fibonacci(n):
	if n<=1:
		return n
	else:
		return fibonacci(n-1) + fibonacci(n-2)
def print_fibonacci_series(n):
	for i in range(n):
		print(fibonacci(i),end="")
n=10
print_fibonacci_series(n)
