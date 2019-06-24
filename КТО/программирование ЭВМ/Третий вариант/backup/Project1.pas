program Project2;
var
    a: array of integer;
    N, i: integer;
	
begin
    write('Введите кол-во элементов массива: ');
    readln(N);
    SetLength(a,N);
	
    randomize;
    for i := 1 to N do begin
        a[i] := random(100);
        write(a[i],' ');
    end;
    writeln();

    for i := 2 to N do begin
        if (a[i] > a[i - 1]) then
           write(a[i],' ');
    end;

    writeln();
    readln();
end.

