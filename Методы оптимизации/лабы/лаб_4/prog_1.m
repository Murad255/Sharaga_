function prog_1

l=5 ; 
xc=[12; 0];  %����� ����� ����������
q0=[0.7 -1 1] ; %��������� ��������� ������

[q,f]=fminsearch(@dist,q0, [], l, xc) 

%prog15_7 
end