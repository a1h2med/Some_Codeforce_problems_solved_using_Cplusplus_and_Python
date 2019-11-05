output_size = input()
permutation_box_values = input()
input_size = input()
input_plain_text = input()

if ((int(output_size) == int(input_size)) or (int(output_size) < int(input_size))):
    input_binary_plain_text = "{0:08b}".format(int(input_plain_text, 16))

else:
    while(len(input_plain_text) < int(output_size)):
        input_plain_text += input_plain_text
    input_binary_plain_text = "{0:08b}".format(int(input_plain_text, 16))

while (len(input_plain_text)*4 > len(input_binary_plain_text)):
    input_binary_plain_text = "0" + input_binary_plain_text

output_box_values = []
output_text = ''
k = 0
permutation_box_values = permutation_box_values.split(' ')

for j in range(int(output_size)):
    output_box_values.append(int(permutation_box_values[k]))
    k += 1

for i in range(int(output_size)):
    x = output_box_values[i]-1
    output_text += input_binary_plain_text[x]

output_text = hex(int(output_text,2))[2:]
output_text = output_text.upper()
print(output_text)