Input = input()
mod_input , number_input = Input.split(' ')

mod_input = int(mod_input)
number_input = int(number_input)

number_input = number_input%mod_input       # if the number is very large

A1_new = 0
A2_new = 0
A3_new = 0

A1_old = 1
A2_old = 0
A3_old = mod_input

B1 = 0
B2 = 1
B3 = number_input

Q = 0
while True:
    if B3 == 0:
        break
    if B3 == 1:
        break
    A1_new = B1
    A2_new = B2
    A3_new = B3

    Q = int(A3_old/B3)

    B1 = int(A1_old - (Q * A1_new))
    B2 = int(A2_old - (Q * A2_new))
    B3 = int(A3_old - (Q * A3_new))

    A1_old = A1_new
    A2_old = A2_new
    A3_old = A3_new

Additive_inverse = mod_input - number_input

if B3 == 0:
    print("IMPOSSIBLE")
else:
    if B2 < 0:
        B2 = B2 + mod_input
        print(Additive_inverse,B2)
    else:
        print(Additive_inverse,B2)