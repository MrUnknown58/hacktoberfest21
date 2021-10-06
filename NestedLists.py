if __name__ == '__main__':
    l=[]
    n=[]
    o=[]
    for i in range(int(raw_input())):
        name = raw_input()
        score = float(raw_input())
        n.append(score)
        l.append([name,score])
    n.sort()
    a=0
    for i in range(1,len(n)):
        if n[i]!=n[i-1]:
            a=i
            break
    for i in l:
        if i[1]==n[a]:
            o.append(i[0])
    o.sort()
    for i in o:
        print(i)
