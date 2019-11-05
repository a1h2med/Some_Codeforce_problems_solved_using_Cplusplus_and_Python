permutation_box_size = input()
permutation_box_values = input()
k = 0
output_box_values = []
output_key = []
permutation_box_values = permutation_box_values.split(' ')
for j in range(int(permutation_box_size)):
    output_box_values.append(int(permutation_box_values[k]))
    output_key.append(0)
    k += 1

for i in range(int(permutation_box_size)):
    output_key[output_box_values[i]-1] = i+1

output = ' '.join(str(e) for e in output_key)

if 0 in output_key:
    print('IMPOSSIBLE')
else:
    print(output)
    