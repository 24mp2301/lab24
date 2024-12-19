import csv

def read_specific_columns(file_name, column_indices):
    try:
        with open(file_name, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:

                selected_columns = [row[index] for index in column_indices]
                print(selected_columns)
    except FileNotFoundError:
        print(f"The file '{file_name}' was not found.")
    except IndexError:
        print(f"One of the column indices is out of range.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    file_name = "example.csv"
    column_indices = [0, 2]
    read_specific_columns(file_name, column_indices)
