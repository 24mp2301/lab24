class BankAccount:
    def __init__(self, name, account_number, account_type, balance):
        self.name = name
        self.account_number = account_number
        self.account_type = account_type
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ₹{amount}. New balance: ₹{self.balance}")
        else:
            print("Invalid deposit amount. Please enter a positive amount.")

    def withdraw(self, amount):
        if amount > 0 and amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew ₹{amount}. New balance: ₹{self.balance}")
        else:
            print("Insufficient balance or invalid withdrawal amount.")

    def display_details(self):
        print("Account Details:")
        print(f"Name: {self.name}")
        print(f"Account Number: {self.account_number}")
        print(f"Account Type: {self.account_type}")
        print(f"Balance: ₹{self.balance}")


name = input("Enter your name: ")
account_number = input("Enter your account number: ")
account_type = input("Enter your account type (Savings/Current): ")
balance = float(input("Enter your initial balance: "))

account = BankAccount(name, account_number, account_type, balance)


account.display_details()


while True:
    choice = input("Enter 'd' to deposit, 'w' to withdraw, or 'q' to quit: ")

    if choice == 'd':
        amount = float(input("Enter the deposit amount: "))
        account.deposit(amount)
    elif choice == 'w':
        amount = float(input("Enter the withdrawal amount: "))
        account.withdraw(amount)
    elif choice == 'q':
        break
    else:
        print("Invalid choice. Please try again.")

account.display_details()
