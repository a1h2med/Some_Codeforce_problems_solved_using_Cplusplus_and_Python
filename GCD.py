GCD_Input = input()
GCD_Input1 , GCD_Input2 = GCD_Input.split(' ')

GCD_Input1 = int(GCD_Input1)
GCD_Input2 = int(GCD_Input2)

GCD_Number1 = 0
GCD_Number2 = 0

if GCD_Input1> GCD_Input2:
    GCD_Number1 = GCD_Input1
    GCD_Number2 = GCD_Input2
else:
    GCD_Number1 = GCD_Input2
    GCD_Number2 = GCD_Input1
remainder = 1
while (remainder != 0):
    remainder = GCD_Number1%GCD_Number2
    GCD_Number1 = GCD_Number2
    GCD_Number2 = remainder
print(GCD_Number1)