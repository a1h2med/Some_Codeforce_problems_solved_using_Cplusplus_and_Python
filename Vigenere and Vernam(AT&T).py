import math

key_text = input()
plain_text = input()

plain_text = plain_text.replace(" ","")
key_text = key_text.replace(" ","")

One_Time_Pad = "NO"

i = 0
encypted_Vigenere_text = ""
encypted_Vernam_text = ""

if len(key_text) == len(plain_text):
    One_Time_Pad = "YES"

else:
    while(len(key_text) < len(plain_text)):
        key_text += key_text[i]
        if key_text[i] == '\n':
            i=0
        i += 1

for j in range(len(key_text)):
    key_value = ord(key_text[j]) - 65
    plain_text_value = ord(plain_text[j]) - 65

    plain_text_hex = hex(ord(plain_text[j]))
    key_hex = hex(ord(key_text[j]))

    plain_text_hex = int(plain_text_hex,16)
    key_hex = int(key_hex,16)
    encypted_Vernam_value = hex(plain_text_hex ^ key_hex)
    encypted_Vernam_value = encypted_Vernam_value[2:]

    if len(encypted_Vernam_value) == 1:
       encypted_Vernam_value = "0" + encypted_Vernam_value

    encypted_Vernam_value = encypted_Vernam_value.upper()

    encypted_Vernam_text += encypted_Vernam_value

    encypted_Vigenere_value = (key_value+plain_text_value)%26
    encypted_Vigenere_value += 65
    encypted_Vigenere_text += chr(encypted_Vigenere_value)


encypted_Vernam_text = encypted_Vernam_text.replace("x","")
print("Vigenere:",encypted_Vigenere_text)
print("Vernam:",encypted_Vernam_text)
print("One-Time Pad:",One_Time_Pad)