function task_1_1_2v
%открываем граффическое окно задаём начальные параметры 
axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on; 
l=5; 
xc=[9; 0];              %задаём новые координаты
q0=[0.7 -1 1.1] ;       %Изменённый начальный вектор
dq=[-1.5 1.5; -1.5 1.5; 1 5];   %интервалы перемещений

%массывы чисел, нужных для вычисления 
a=transpose(dq(:,1));
b=transpose(dq(:,2));
c=[pi/(b(1)-a(1)) pi/(b(2)-a(2)) pi/(b(3)-a(3))];
z0 = tan((q0 -(a + b)/2).* c);
%рисуем начальное полжение пунктиром
[XInit,YInit]=hinges(q0,l); 
plot(XInit, YInit,'k:'); 

%вычисляем значения углов и рисуем конечное полжение 
z=fminsearch(@distz,z0, [], l, xc,dq) 
%[q,fs, e, inf]=fminsearch(@dist,q0, [], l, xc) 
q = (b - a)/pi.*atan(z) + (a + b)/2;

[XOptim,YOptim]=hinges(q,l); 
plot(XOptim, YOptim,'k-','LineWidt',2); 

%отрисовываем элементы оформления
plot([0],[-0.3],'k^','MarkerSize',15);
plot(XInit(1:2), YInit(1:2),'ko'); 
plot([XInit(3)], [YInit(3)],'ks', 'MarkerSize', 15); 
plot(XOptim(1:2), YOptim(1:2),'ko'); 
plot([XOptim(3)], [YOptim(3)],'ks', 'MarkerSize', 15); 
xlabel('x1'); ylabel('x2'); 
legend('Начальное','Конечное');
title('Два положения манипулятора'); 
end

function [X,Y] = hinges(q,l)
x=[l*cos(q(1)) q(3)*cos(q(1)+q(2))]; 
y=[l*sin(q(1)) q(3)*sin(q(1)+q(2))]; 
x=[0 x]; y=[0 y]; X=cumsum(x); Y=cumsum(y);  
end

function d=distz(z,l,xc,dq)
a=transpose(dq(:,1));
b=transpose(dq(:,2));
q = (b - a)/pi.*atan(z) + (a + b)/2;
x=coord(q,l); 
d=norm(x-xc);
end
function x=coord(q,l) 
x1=l*cos(q(1))+q(3)*cos(q(1)+q(2)); 
y1=l*sin(q(1))+q(3)*sin(q(1)+q(2)); 
x=[x1; y1]; 
end