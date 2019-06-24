program project1;
var
  k,n:byte;
  x,y,sum:real;

begin
  repeat
    writeln('Введите x не равно 0');
    readln(x);
  until x<>0;
  repeat
    writeln ('Введите N от 2 до 50');
    readln(n);
  until (n>1) and (n<=50);
  sum:=0;
  for k:=1 to n do
  sum:=sum+(ln(sqrt(k*abs(x)+2)))/(sqrt(abs(x)));
  y:=exp(5*ln(x))+sum;
  writeln('y=' ,y);
  readln
end.

