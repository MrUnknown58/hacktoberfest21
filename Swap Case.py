def swap_case(s):
    p=''
    for i in s:
        c=i
        if i.isalpha()==True:
            if i.isupper()==True:
                c=i.lower()
            else:
                c=i.upper()
        p+=c
    return p

if __name__ == '__main__':
