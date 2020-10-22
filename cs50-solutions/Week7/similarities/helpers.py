from nltk.tokenize import sent_tokenize
def substring(a,b,n):
    a_sub=list()
    b_sub=list()
    ortak_sub=list()
    for i in range(len(a)-n+1):
        a_sub.append(a[i:i+n])
    for j in range(len(b)-n+1):
        b_sub.append(b[j:j+n])
    for k in a_sub:
        for l in b_sub:
            if k==l:
                if k in ortak_sub:
                    continue
                else:
                    ortak_sub.append(k)
            else:
                continue
    return list(ortak_sub)
def lines(a, b):
    """Return lines in both a and b"""
    a_satir=a.split("\n")
    b_satir=b.split("\n")
    ortak_keli=list()
    for i in a_satir:
        for j in b_satir:
            if i==j:
                if i in ortak_keli:
                    continue
                else:
                    ortak_keli.append(i)
            else:
                continue
    return list(ortak_keli)
def sentences(a, b):
    ortak_cum=list()
    """Return sentences in both a and b"""
    a_cumle=sent_tokenize(a)
    b_cumle=sent_tokenize(b)
    for i in a_cumle:
        for j in b_cumle:
            if i==j:
                if i in ortak_cum:
                    continue
                else:
                    ortak_cum.append(i)
            else:
                continue
    return list(ortak_cum)
def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    ortak_subs=substring(a,b,n)
    return list(ortak_subs)