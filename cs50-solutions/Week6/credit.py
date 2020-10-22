from cs50 import get_int,get_string
isTrue=False
while isTrue==False:
    card_number = get_string("Number:")
    if card_number.isdigit():
        break
toplam1=0
toplam2=0
toplam3=0
for i in range(len(card_number)-2,-1,-2):
    if (int(card_number[i]))*2>=10:
        toplam2+=(2*int(card_number[i]))-9
    else:
        toplam2+=(2*int(card_number[i]))
for j in range(len(card_number)-1,-1,-2):
    toplam1+=int(card_number[j])
toplam3=toplam1+toplam2
card=""
if toplam3%10==0:
    if (len(card_number)==13 or len(card_number)==16) and card_number[0]=='4':
        card="VISA"
    elif len(card_number)==15 and (card_number[0]=='3' and (card_number[1]=='4' or card_number[1]=='7')):
        card="AMEX"
    elif len(card_number)==16 and (card_number[0]=='5' and (card_number[1]=='1' or card_number[1]=='2' or card_number[1]=='3' or card_number[1]=='4' or card_number[1]=='5')):
        card="MASTERCARD"
    else:
        card="INVALID"
else:
    card="INVALID"
print(card)