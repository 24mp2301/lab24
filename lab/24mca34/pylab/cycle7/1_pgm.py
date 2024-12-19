def read_file_to_list(filename):
    try:
        with open(filename, 'r') as file:
            return [line.strip() for line in file]
    except FileNotFoundError:
        print(f"The file '{filename}' was not found.")
        return []
    except Exception as e:
        print(f"An error occurred: {e}")
        return []

if __name__ == "__main__":
    filename = "hello.txt"  
    lines = read_file_to_list(filename)

    if lines:
        print("Lines from the file:")
        for line in lines:
            print(line)
