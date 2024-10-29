i =int(input())
temp=i
ans=0
while temp >0:
    p=temp%10
    ans+=p*p*p
    temp//=10

if ans==i : print("Armstrong number")
else :print("Not a armstrong number")  

