import csv


num_entries = int(input("Enter the number of entries you want to add: "))


names = []
ages = []
cities = []


for i in range(num_entries):
    name = input(f"Enter name{i+1}: ")
    age = input(f"Enter age for {name}: ")
    city = input(f"Enter city for {name}: ")


    names.append(name)
    ages.append(age)
    cities.append(city)


data = {
    'Name': names,
    'Age': ages,
    'City': cities
}


with open('data.csv', mode='w', newline='') as file:
    writer = csv.DictWriter(file, fieldnames=data.keys())
    writer.writeheader()

    for i in range(len(data['Name'])):
        row = {key: data[key][i] for key in data}
        writer.writerow(row)

with open('data.csv', mode='r') as file:
    reader = csv.DictReader(file)

    print("\nCSV file contents:")
    for row in reader:
        print(row)
