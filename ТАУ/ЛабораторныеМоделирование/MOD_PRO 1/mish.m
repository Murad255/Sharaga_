function msi=mish(x)
%No dead zone
%Not standart function
y=abs(x)
if y<.1 msi=0
else
   msi=sign(x)
   end