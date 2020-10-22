from cs50 import get_float

while True:
    c=get_float("Change owed:")
    if c>0 and float(c):
        break
c=c*100
c=round(c)
counter=0
while True:
    if ((int)(c)/(25))!=0:
        counter+=c//25
        c=c-(c//25)*25
    if ((int)(c)/(10))!=0:
        counter+=c//10
        c=c-(c//10)*10
    if ((int)(c)/(5)!=0):
        counter+=c//5
        c=c-(c//5)*5
    if ((int)(c)/(1)!=0):
        counter+=c//1
        c=c-(c//1)*1
    break
print(f"{counter}")