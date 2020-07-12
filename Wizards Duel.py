# solution to 591/
from fractions import Fraction

Corridor_Length = float(input())
Harry_Speed = float(input())
You_Know_Speed = float(input())
Relative_Speed = 0.0
flag = 0
if Harry_Speed == You_Know_Speed:
    print(Corridor_Length / 2)
else:
    if (Harry_Speed < You_Know_Speed):
        Relative_Speed = Harry_Speed / You_Know_Speed
    else:
        flag = 1
        Relative_Speed = You_Know_Speed / Harry_Speed
    x = str(Fraction(str(Relative_Speed)).limit_denominator(1000))
    divisor_location = x.find('/')
    first_fraction = x[:divisor_location]
    second_fraction = x[divisor_location+1:]
    summation = int(first_fraction) + int(second_fraction)
    div = Corridor_Length / summation
    if flag == 1:
        Har_out = int(second_fraction) * div
    else:
        Har_out = int(first_fraction) * div

    print(Har_out)