Key = input()
#plain_text = "0123456789ABCDEF0123456789ABCDEF"
plain_text = input()
Number_of_reputetion = input()
sbox = [
        0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
        0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
        0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
        0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
        0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
        0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
        0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
        0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
        0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
        0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
        0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
        0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
        0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
        0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
        0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
        0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
]

Mix_col = [
    "02", "03", "01", "01",
    "01", "02", "03", "01",
    "01", "01", "02", "03",
    "03", "01", "01", "02"
]

def subBytes(text):
    output_list = []
    for i in range(len(text)):
        text[i] = sbox[text[i]]
        nn = hex(text[i])[2:]
        if len(nn) < 2:
            nn = "0" + nn
        nn = nn.upper()
        output_list.append(nn)

    return output_list

def prepare_input(text):
    list_of_output = []
    list_of_integers = []
    list_n = []
    i = 0
    while i < len(text):
        t = text[i]
        t1 = text[i+1]
        t2 = t+t1
        t3 = int(t2,16)
#        list_of_integers.append(t3)
        list_of_output.append(t2)
        list_n.append(t2)
        i = i + 2

    i = 0
    j = 0
    counter = 1
    while i < len(list_of_output):
        list_of_output[i] = list_n[j]
        t3 = int(list_n[j],16)
        list_of_integers.append(t3)
        if j == 12 or j > 12:
            j = counter
            counter += 1
            i += 1
            continue
        j += 4
        i += 1

    return list_of_output, list_n, list_of_integers

def rotation(text, n):
    return text[n:] + text[0:n]

def shifting(text):
    for i in range(4):
        text[i*4:i*4+4] = rotation(text[i*4:i*4+4],i)
    return text

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


def Multiplication(First_Number,Second_Number):
    if First_Number == "00":
        return "00"
    elif Second_Number == "00":
        return "00"

    First_Number_Binary = Binary_Conversion(First_Number)
    Second_Number_Binary = Binary_Conversion(Second_Number)
    Generator = Binary_Conversion("1B")

    Shift_List = []

    if Second_Number_Binary[len(Second_Number_Binary) - 1] == "1":
        Shift_List.append(First_Number_Binary)

    i = 0
    Shift_output = First_Number_Binary
    Second_Number_Binary = Second_Number_Binary[:-1]
    j = len(Second_Number_Binary) - 1
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
        Final_Output = Xor(Shift_List[x], Final_Output)

    Multiplication = hex(int(Final_Output, 2))
    Multiplication = Multiplication[2:]
    while len(Final_Output) / 4 > len(Multiplication):
        Multiplication = "0" + Multiplication

    Multiplication = Multiplication.upper()

    return Multiplication

def Mix_Columns(plain_text_list_columns):

    Mul_list = []
    Mul_Final = []
    j = 0
    z = 0
    counter = 0
    i = 0
    for n in range(len(plain_text_list_columns)*4):
        if i%4 == 0:
            z = counter
        xxxx = Multiplication(Mix_col[z], plain_text_list_columns[i])
        Mul_list.append(xxxx)
        if j == 3:
            output = Mul_list[0]
            output = Binary_Conversion(output)
            for x in range(1, len(Mul_list)):
                n = Binary_Conversion(Mul_list[x])
                output = Xor(n, output)

            output1 = hex(int(output, 2))
            output1 = output1[2:]
            while len(output) / 4 > len(output1):
                output1 = "0" + output1
            output1 = output1.upper()
            Mul_Final.append(output1)
            j = 0
            Mul_list.clear()
            if i == 15:
                counter += 4
                i = 0
                continue

            i += 1
            continue
        j += 1
        z += 1
        i += 1

    return Mul_Final

def rowTocolumn(row):
    list_of_output = []
    list_of_integers = []
    list_n = [0 for L in range(len(row))]

    i = 0
    j = 0
    counter = 1
    while i < len(row):
        list_n[i] = row[j]
#        t3 = int(list_n[j], 16)
#        list_of_integers.append(t3)
        if j == 12 or j > 12:
            j = counter
            counter += 1
            i += 1
            continue
        j += 4
        i += 1

    return list_of_output, list_n, list_of_integers

def Add_round_key(text,key):
    output = []
    int_out = []
    for i in range(len(text)):
        temp1 = Binary_Conversion(text[i])
        temp2 = Binary_Conversion(key[i])
        temp3 = Xor(temp1,temp2)
        temp4 = int(temp3, 2)
        int_out.append(temp4)
        Addition = hex(temp4)
        Addition = Addition[2:]
        while len(temp3) / 4 > len(Addition):
            Addition = "0" + Addition

        Addition = Addition.upper()
        output.append(Addition)

    return output, int_out

def bintohex(number):
    temp = int(number, 2)
    Addition = hex(temp)
    Addition = Addition[2:]
    while len(number) / 4 > len(Addition):
        Addition = "0" + Addition
    Addition = Addition.upper()
    return Addition

def WORDS(key):
    words = []
    j = 0
    for i in range(len(key)+1):
        if i%4 == 0 and i != 0:
            w = key[j:(i)]
            words.append(w)
            j = i
    return words

def Word_operation(key,round_number):
    Words = WORDS(key)
    Shifting_word = rotation(Words[3],1)
    x = []
    for i in range(4):
        x.append(int(Shifting_word[i],16))
    Substituted = subBytes(x)
    round_const = [
        "01", "02", "04", "08", "10", "20", "40", "80", "1B", "36"
    ]
    bin_round = Binary_Conversion(round_const[round_number])
    bin_subst = Binary_Conversion(Substituted[0])
    temp3 = Xor(bin_round, bin_subst)
    temp4 = int(temp3, 2)
    Addition = hex(temp4)
    Addition = Addition[2:]
    while len(temp3) / 4 > len(Addition):
        Addition = "0" + Addition

    Addition = Addition.upper()
    output = []
    output.append(Addition)
    for i in range(1,4):
        output.append(Substituted[i])
    return output

def Key_expansion(key,round_number):
    word = WORDS(key)
    word_operated = Word_operation(key,round_number)
    new_word_output = []
    Xor_output1 = []
    Xor_output2 = []
    Xor_output3 = []
    Xor_output4 = []
    hex_output1 = []
    hex_output2 = []
    hex_output3 = []
    hex_output4 = []

    for i in range(4):
        bin_round = Binary_Conversion(word[0][i])
        bin_subst = Binary_Conversion(word_operated[i])
        Xor_output1.append(Xor(bin_round, bin_subst))
        hex_output1.append(bintohex(Xor_output1[i]))

    for i in range(4):
        bin_round = Binary_Conversion(word[1][i])
        Xor_output2.append(Xor(bin_round, Xor_output1[i]))
        hex_output2.append(bintohex(Xor_output2[i]))

    for i in range(4):
        bin_round = Binary_Conversion(word[2][i])
        Xor_output3.append(Xor(bin_round, Xor_output2[i]))
        hex_output3.append(bintohex(Xor_output3[i]))

    for i in range(4):
        bin_round = Binary_Conversion(word[3][i])
        Xor_output4.append(Xor(bin_round, Xor_output3[i]))
        hex_output4.append(bintohex(Xor_output4[i]))

    output = ""
#    output.append(hex_output1)
#    output.append(hex_output2)
#    output.append(hex_output3)
#    output.append(hex_output4)
    output = hex_output1 + hex_output2 + hex_output3 + hex_output4
    return output

def generate_all_keys(key):
    generated_key = []

    generated_key.append(key)

    new_key0 = Key_expansion(key,0)
    generated_key.append(new_key0)

    new_key1 = Key_expansion(new_key0, 1)
    generated_key.append(new_key1)

    new_key2 = Key_expansion(new_key1, 2)
    generated_key.append(new_key2)

    new_key3 = Key_expansion(new_key2, 3)
    generated_key.append(new_key3)

    new_key4 = Key_expansion(new_key3, 4)
    generated_key.append(new_key4)

    new_key5 = Key_expansion(new_key4, 5)
    generated_key.append(new_key5)

    new_key6 = Key_expansion(new_key5, 6)
    generated_key.append(new_key6)

    new_key7 = Key_expansion(new_key6, 7)
    generated_key.append(new_key7)

    new_key8 = Key_expansion(new_key7, 8)
    generated_key.append(new_key8)

    new_key9 = Key_expansion(new_key8, 9)
    generated_key.append(new_key9)

    return generated_key


def encryption(key_output_columns,ADDD, index1):

    plain_text_sub_output_columns = subBytes(ADDD)
    _,plain_text_sub_output_rows,_ = rowTocolumn(plain_text_sub_output_columns)

    shifted_list = shifting(plain_text_sub_output_rows)
    _,col_shifted,_ = rowTocolumn(shifted_list)

    Mix_Col_output_row = Mix_Columns(col_shifted)

    _,Mix_Col_output_Columns,_ = rowTocolumn(Mix_Col_output_row)

    _,key_output_row,_ = rowTocolumn(key_output_columns[index1])

    Addition_col,_ = Add_round_key(Mix_Col_output_row,key_output_row)
    _, Addition_Row, _ = rowTocolumn(Addition_col)
    return Addition_Row


def hextodecimal(number):
    x = []
    for i in range(len(number)):
        x.append(int(number[i],16))
    return x

def Full_Rounds(Key,plain_text):
    Key_list_rows, Key_list_columns, Key_integer = prepare_input(Key)
    plain_text_list_rows, plain_text_list_columns, plain_text_integer = prepare_input(plain_text)

    key_output_columns = generate_all_keys(Key_list_columns)
    _, key_output_row, _ = rowTocolumn(key_output_columns[0])

    _,Add_Output = Add_round_key(key_output_row,plain_text_list_rows)
    _,ADDD,_ = rowTocolumn(Add_Output)

    Out1 =  encryption(key_output_columns,ADDD,1)
    Out1 = hextodecimal(Out1)

    Out2 = encryption(key_output_columns, Out1, 2)
    Out2 = hextodecimal(Out2)

    Out3 = encryption(key_output_columns, Out2, 3)
    Out3 = hextodecimal(Out3)

    Out4 = encryption(key_output_columns, Out3, 4)
    Out4 = hextodecimal(Out4)

    Out5 = encryption(key_output_columns, Out4, 5)
    Out5 = hextodecimal(Out5)

    Out6 = encryption(key_output_columns, Out5, 6)
    Out6 = hextodecimal(Out6)

    Out7 = encryption(key_output_columns, Out6, 7)
    Out7 = hextodecimal(Out7)

    Out8 = encryption(key_output_columns, Out7, 8)
    Out8 = hextodecimal(Out8)

    Out9 = encryption(key_output_columns, Out8, 9)
    Out9 = hextodecimal(Out9)

    plain_text_sub_output_columns = subBytes(Out9)
    _, plain_text_sub_output_rows, _ = rowTocolumn(plain_text_sub_output_columns)

    shifted_list = shifting(plain_text_sub_output_rows)
    _, col_shifted, _ = rowTocolumn(shifted_list)

    _, key_output_row, _ = rowTocolumn(key_output_columns[10])

    Add_Output,_  = Add_round_key(key_output_columns[10], col_shifted)
    _, ADDD, _ = rowTocolumn(Add_Output)

    FINAL_OUTPUT = ""
    for i in range(len(Out1)):
        c = hex(Out1[i])
        c = c[2:]
        c = c.upper()
        if len(c) < 2:
            c = "0"+c
        FINAL_OUTPUT += c

    return ADDD


ii = 0
while ii < int(Number_of_reputetion):
    if Number_of_reputetion == 0:
        break
    x = Full_Rounds(Key, plain_text)
    _, x, _ = rowTocolumn(x)
    Output = ""
    for iii in range(len(x)):
        Output += x[iii]
    plain_text = Output
    ii += 1

print(plain_text)