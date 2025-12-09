filename = "input.txt"


operations = []
file = open(filename, "r")
for line in file:
    operations.append(line.split(" "))
    
print(operations) 