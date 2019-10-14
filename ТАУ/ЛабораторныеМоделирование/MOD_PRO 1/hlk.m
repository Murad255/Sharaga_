function hl=hlk(x)
%Domains
%Not standart function
y=abs(x)
if y>=.25 hl=0
else
   if y>=.1 hl=2   
   else hl=15
   end
end