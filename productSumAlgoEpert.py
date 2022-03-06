def ProdSum(l, multi=1):
    
    sum=0
    for i in l:
        if(type(i) is list):
            sum+=ProdSum(i, multi+1);
        else:
            sum+=i;
    return sum*multi;

l = [5, 2, [7, -1], 3, [6, [-13 , 8], 4]]
print(ProdSum(l, 1))
