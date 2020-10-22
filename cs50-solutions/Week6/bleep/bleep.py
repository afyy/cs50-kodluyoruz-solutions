from cs50 import get_string
from sys import argv
import sys


def main(argv):
    file=open(argv[1],"r")
    words=""
    for i in file:
        words=words+i
    words=words.split('\n')
    plaintext=get_string("What message would you like to censor?\n")
    liste=plaintext.split()
    for i in range(len(liste)):
        for j in range(len(words)):
            if liste[i].lower()==words[j]:
                print("*"*len(liste[i]),end="")
                if i== len(liste)-1:
                    print()
                else:
                    print(" ",end="")
                break
            if j==len(words)-1:
                print(liste[i],end="")
                if i== len(liste)-1:
                    print()
                else:
                    print(" ",end="")
if __name__ == "__main__":
    if len(argv)!=2:
        sys.exit(1)
    main(argv)