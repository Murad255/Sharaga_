function msi1=mish1(x)
%No dead zone
%Not standart function
y=abs(x)
if y<.001 msi1=0
else
   msi1=sign(x)
   end