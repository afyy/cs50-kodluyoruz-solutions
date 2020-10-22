from sys import argv
from cs50 import get_string
    
k = int(argv[1])
plaintext=get_string("plaintext: ")
print("ciphertext: ",end="")
ch=""
for i in range(0,len(plaintext)):
    if ord(plaintext[i]) >= 65 and ord(plaintext[i]) <= 90:
        print(chr((ord(plaintext[i])-65+k)%26+65),end="")
    elif ord(plaintext[i]) >= 97 and ord(plaintext[i]) <= 122:
        print(chr((ord(plaintext[i])-97+k)%26+97),end="")
    else:
        print(plaintext[i],end="")
print()
 k = (ord(c) - 65 + q) % 26 + 65
 x = chr(k)
 t = (ord(c) - 97 + q) % 26 + 97
 y = chr(t)