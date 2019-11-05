import math

key_length = input()
key_parameters = input()
plain_text = input()

rows_and_columns_length = math.sqrt(int(key_length))

key_matrix = [[]for i in range(int(rows_and_columns_length))]

counter = 0
encrypted_message = ""

key_parameters = key_parameters.split(' ')

for i in range(int(rows_and_columns_length)):
    for j in range(int(rows_and_columns_length)):
        key_matrix[i].append(int(key_parameters[counter]))
        counter = counter + 1

counter1 = 0
counter2 = int(rows_and_columns_length)
flag = 0

plain_text = plain_text.replace(" ","")

plain_text_value = []
result_encrypted = []

iterations = math.ceil(len(plain_text)/int(rows_and_columns_length))

for i in range(iterations):
    plain_text_matrix = plain_text[counter1:counter2]
    while (len(plain_text_matrix) < int(rows_and_columns_length)):
        plain_text_matrix = plain_text_matrix + "X"
        flag = 1
    for j in range(int(rows_and_columns_length)):
        time = ord(plain_text_matrix[j]) - 65
        plain_text_value.append(time)

    for z in range(int(rows_and_columns_length)):
        counter3 = 0
        sum = 0
        for x in range(int(rows_and_columns_length)):
            sum += key_matrix[z][x] * plain_text_value[counter3]
            counter3 = counter3 + 1
        sum = sum%26
        sum = sum + 65
        encrypted_message += chr(sum)


    if flag == 1:
        break
    counter1 = counter2
    counter2 = counter2 + int(rows_and_columns_length)
    plain_text_value.clear()
	

1100_0011_1100_0011_1100_0011_1111_1100_0011_1100_0011_1100_0011_1111'

1100_0011_1100_0011_1100_0011_1111_1100_0011_1100_0011_1100_0011_1111


'f0f0ff0f0f0ff'
'0000111100001111000011111111'
'0000111100001111000011111111'

'0000111100001111000011111111'

'1110000111100001111000011111'
print(encrypted_message)
0000111100001111000011111111