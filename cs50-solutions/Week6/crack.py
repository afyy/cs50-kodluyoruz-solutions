from sys import argv
import crypt
import sys
if len(argv)!=2:
    print("Usage: python crack.py hash")
    sys.exit(0)
letters_count = 52
letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
heş = argv[1]
salt=[]
salt.append(heş[0])
salt.append(heş[1])
key_candidate=['\0','\0','\0','\0','\0','\0']
for i in range(letters_count):
    for j in range(letters_count):
        for k in range(letters_count):
            for l in range(letters_count):
                for m in range(letters_count):
                    key_candidate[0] = letters[m]
                    key_candidate[1] = letters[l]
                    key_candidate[2] = letters[k]
                    key_candidate[3] = letters[j]
                    key_candidate[4] = letters[i]
                    print(crypt.crypt(str(key_candidate),str(salt)))#==heş:
print("Password couldn't be cracked!")
sys.exit(0)