program project1;
var
  k,n: byte;
  x,y,sum: real;

begin
  repeat
  writeln('Введите x не равно 0');
  readln(x);
  until x<>0;
  repeat
    writeln ('Введите N>0');
    readln (n);
    until (n>0);
    sum:=0;
    for k:=1 to n do
    sum:=sum+(((exp(1/3*ln(x)))/k)-exp(-k*x))*sin(k*x);
    y:=(1)/((exp(2*ln(x)))+x)*sum;
    writeln ('y=' ,y);
    readln
end.

