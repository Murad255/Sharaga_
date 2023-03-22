function prog15_7
%��������� ������������ ���� ����� ��������� ��������� 
axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on; 
l=[5 5 5]; 
xc=[12; 0];            %����� ����� ����������
q0=[0.7 -1 0.5];        %��������� ��������� ������
dq=[-2 2;-2 2;-2 2];    %��������� �����������

z0 = tan(q0 *pi /4 )

%������ ��������� �������� ���������
[XInit,YInit]=hinges(q0,l); 
plot(XInit, YInit,'k:'); 

%��������� �������� ����� � ������ �������� �������� 
[z,fs, e, inf]=fminsearch(@distz,z0, [], l, xc) 
q = 4/pi*atan(z);
[XOptim,YOptim]=hinges(q,l); 
plot(XOptim, YOptim,'k-','LineWidt',2); 

%������������ �������� ����������
plot([0],[-0.3],'k^','MarkerSize',15);
plot(XInit(1:3), YInit(1:3),'ko'); 
plot([XInit(4)], [YInit(4)],'ks', 'MarkerSize', 15); 
plot(XOptim(1:3), YOptim(1:3),'ko'); 
plot([XOptim(4)], [YOptim(4)],'ks', 'MarkerSize', 15); 
xlabel('x1'); ylabel('x2'); 
legend('���������','��������');
title('��� ��������� ������������'); 
end

function [X,Y] = hinges(q,l)
Q=cumsum(q); 
x=l.*cos(Q); 
y=l.*sin(Q);
x=[0 x]; y=[0 y]; X=cumsum(x); Y=cumsum(y);  
end


function d=distz(z,l,xc)%,q0) 
q = 4/pi*atan(z);
x=coord(q,l); 
d=norm(x-xc); 
end

function x=coord(q,l) 
Q=cumsum(q); 
x=[sum(l.*cos(Q)); sum(l.*sin(Q))]; 
end
