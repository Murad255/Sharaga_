program one;
var
  x,n,sum,k: real;

begin

  writeln('write the number x: \n');
  readln(x);
  writeln('write the number n: \n');
  readln(n);
  k:=0;
  sum:=0 ;
  repeat
     sum:=sum+Exp(ln(x)*(k-1))*Exp(ln(ln(x+1) )*(k));
      k:=k-1;
    until (k>0);
       sum:=sum*Exp(-x)/(cos(x)+2);

   writeln('sum= ',sum);
    readln
end.

