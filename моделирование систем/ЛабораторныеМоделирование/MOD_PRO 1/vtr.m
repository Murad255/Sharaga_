function vre=vtr(x)
%Ogranichitel dlja asin
y=abs(x)
if y<=1 vre=asin(x)
else vre=sign(x)*pi/2
   end