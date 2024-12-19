def copy_odd_lines(source_file, destination_file):
    try:

        with open(source_file, 'r') as src, open(destination_file, 'w') as dest:

            for i, line in enumerate(src, start=1):
                if i % 2 != 0:
                    dest.write(line)
        print(f"Odd lines from '{source_file}' have been copied to '{destination_file}'.")
    except FileNotFoundError:
        print(f"The file '{source_file}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    source_file = "main.txt"
    destination_file = "odd.txt"
    copy_odd_lines(source_file, destination_file)

try:
        print("\nContents of the source file:")
        with open(source_file, 'r') as source:
                for line in source:
                        print(line, end='')
except FileNotFoundError:
        print(f"The file '{source_file}' was not found.")
except Exception as e:
        print(f"An error occurred while reading the file: {e}")

try:
	print("\nContents of the destination file:")
	with open(destination_file, 'r') as dest:
		for line in dest:
			print(line, end='')
except FileNotFoundError:
	print(f"The file '{destination_file}' was not found.")
except Exception as e:
	print(f"An error occurred while reading the file: {e}")

