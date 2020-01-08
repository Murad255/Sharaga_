function pur=purp(f1,f2,f3,x)
%Calculation of choice
y=x;
a1=abs(y-f1);
a2=abs(y-f2);
a3=abs(y-f3);
if a2<a1
   b=a2;
   pur=f2;
else b=a1;
     pur=f1;
     end;
     if a3<b
        pur=f3;
     end;
end;