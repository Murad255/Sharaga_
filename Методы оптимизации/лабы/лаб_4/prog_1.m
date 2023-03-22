function prog_1

l=5 ; 
xc=[12; 0];  %задаём новые координаты
q0=[0.7 -1 1] ; %Изменённый начальный вектор

[q,f]=fminsearch(@dist,q0, [], l, xc) 

%prog15_7 
end