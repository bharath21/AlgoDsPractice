a=[0 for i in range(101)]
a[0]=1
for i in range(1,101):
      a[i]=i*a[i-1]

tc = int(input().strip())

while tc!=0:
      tc-=1
      n=int(input().strip())
      print(a[n])
