program project1;
var
   k,n:integer;
   x,y,sum:real;
begin
  repeat
   writeln('Введите x,неравный 0');
   readln(x);
  until (x<>0);
  repeat
   writeln('Введите N > 0');
   readln(n);
  until (n>0) and ((x=1)and (n<2));
  sum:=0;
  for k:=1 to n do
   sum:=sum+(1+(sin(x)/cos(x)))/(exp(1/3*ln(2*x-k)));
  y:=(2*x+exp(x))*sum;
  writeln('y=',y);
  readln;
end.

