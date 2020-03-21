Input = input()

First_Number, Second_Number = Input.split(' ')

def Binary_Conversion(Number):

    length_of_Number = len(Number)

    Binary_Number = bin(int(Number, 16))[2:]

    length_of_Binary_Number = len(Binary_Number)

    while length_of_Binary_Number < length_of_Number*4:
        Binary_Number = "0"+Binary_Number
        length_of_Binary_Number = len(Binary_Number)

    return Binary_Number

def Xor(Number1,Number2):

    length_of_output = len(Number1)             # if the two inputs are not from the same size that will give you an error

    Binary_Number1 = int(Number1, 2)
    Binary_Number2 = int(Number2, 2)

    Int_Output = Binary_Number1 ^ Binary_Number2

    Binary_Output = '{0:b}'.format(Int_Output)

    Binary_Output_Length = len(Binary_Output)

    while Binary_Output_Length < length_of_output:
        Binary_Output = "0" + Binary_Output
        Binary_Output_Length = len(Binary_Output)

    return Binary_Output

def Shift_Left(Binary_Number):

    Int_Number1 = int(Binary_Number, 2)
    Int_Shift = Int_Number1 << 1
    Binary_Number1 = '{0:b}'.format(Int_Shift)

    length_of_output = len(Binary_Number)
    Binary_Output_Length = len(Binary_Number1)

    if Binary_Output_Length < length_of_output:
        while Binary_Output_Length < length_of_output:
            Binary_Number1 = "0" + Binary_Number1
            Binary_Output_Length = len(Binary_Number1)

    else:
        while Binary_Output_Length > length_of_output:
            Binary_Number1 = Binary_Number1[1:]
            Binary_Output_Length = len(Binary_Number1)

    return Binary_Number1

First_Number_Binary = Binary_Conversion(First_Number)
Second_Number_Binary = Binary_Conversion(Second_Number)
Generator = Binary_Conversion("1B")

Shift_List = []
#
#
#
#
############## Addition Code Start #############
#
#
#
#

Temp = Xor(First_Number_Binary,Second_Number_Binary)
Addition = hex(int(Temp, 2))
Addition = Addition[2:]

while len(First_Number_Binary)/4 > len(Addition):
    Addition = "0" + Addition

#
#
#
#
############## Multiplication Code Start #############
#
#
#
#

if len(Second_Number_Binary) > len(First_Number_Binary):
    
    if First_Number_Binary[len(First_Number_Binary)-1] == "1":
        Shift_List.append(Second_Number_Binary)
        
    First_Number_Binary = First_Number_Binary[:-1]
    Shift_output = Second_Number_Binary
    i = 0
    J = len(First_Number_Binary) - 1
    while i < len(First_Number_Binary):

        if Shift_output[0] == "1":
            Shift_output = Shift_Left(Shift_output)
            Shift_output = Xor(Shift_output,Generator)

        else:
            Shift_output = Shift_Left(Shift_output)

        if First_Number_Binary[J] == "1":
            Shift_List.append(Shift_output)
        i += 1
        J -= 1
else:
    
    if Second_Number_Binary[len(Second_Number_Binary)-1] == "1":
        Shift_List.append(First_Number_Binary)
    
    i = 0
    Shift_output = First_Number_Binary
    Second_Number_Binary = Second_Number_Binary[:-1]
    j = len(Second_Number_Binary)-1
    while i < len(Second_Number_Binary):

        if Shift_output[0] == "1":
            Shift_output = Shift_Left(Shift_output)
            Shift_output = Xor(Shift_output, Generator)

        else:
            Shift_output = Shift_Left(Shift_output)

        if Second_Number_Binary[j] == "1":
            Shift_List.append(Shift_output)
        i += 1
        j -= 1

Final_Output = Shift_List[0]
for x in range(1, len(Shift_List)):
    Final_Output = Xor(Shift_List[x],Final_Output)

Multiplication = hex(int(Final_Output, 2))
Multiplication = Multiplication[2:]
while len(Final_Output)/4 > len(Multiplication):
    Multiplication = "0" + Multiplication

Addition = Addition.upper()
Multiplication = Multiplication.upper()
print(Addition, Multiplication)