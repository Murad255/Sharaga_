K=1; T=2; dzita=0.1;	% ��������� �������������� �����
% ���������� �������������� ������ �� ����������� �����
%dzita=0.1; [a,b,c,d]=linmod('lab1_2'); sys1=ss(a, b, c, d);
dzita=0.5; [a,b,c,d]=linmod('lab1_2'); sys2=ss(a, b, c, d);
%dzita=0.7; [a,b,c,d]=linmod('lab1_2'); sys3=ss(a, b, c, d);
dzita=0.9; [a,b,c,d]=linmod('lab1_2'); sys4=ss(a, b, c, d);

%���������� ���������� �������
figure(1); set(1,'Name', '���������� �������');
time=17;
step (sys1(1,1), sys2(1,1), sys3(1,1), sys4(1,1), time), grid;

%���������� ��������� �������������
figure(2); set(2,'Name', '�����');
omega=logspace (-2,2);
bode (sys1(1,1), sys2(1,1), sys3(1,1), sys4(1,1), omega), grid;
