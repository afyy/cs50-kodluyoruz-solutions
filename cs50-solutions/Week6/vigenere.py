from sys import argv
from cs50 import get_string
import sys
if len(argv)!=2:
    print("Usage: python vigenere.py key")
    sys.exit(1)
if argv[1].isalpha()==False:
    print("Usage: python vigenere.py key")
    sys.exit(1)
p=get_string("plaintext: ")
j=0
print("ciphertext: ",end="")
for i in range(len(p)):
    if p[i].isalpha() and p[i].isupper():
        if j==len(argv[1]):
            j=0
        if argv[1][j].isupper():
            print(chr((ord(p[i])-65+ord(argv[1][j])%65)%26+65),end="")
        else:
            print(chr((ord(p[i])-65+ord(argv[1][j])%97)%26+65),end="")
        j+=1
    elif p[i].isalpha() and p[i].islower():
        if j==len(argv[1]):
            j=0
        if argv[1][j].isupper():
            print(chr((ord(p[i])-97+ord(argv[1][j])%65)%26+97),end="")
        else:
            print(chr((ord(p[i])-97+ord(argv[1][j])%97)%26+97),end="")
        j+=1
    else:
        print(p[i],end="")
print()