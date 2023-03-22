function prog15_7
%открываем граффическое окно задаём начальные параметры 
axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on; 
l=[5 5 5]; 
xc=[10; 10];    %задаём новые координаты
q0=[0.7 -1 0.5];  %Изменённый начальный вектор

%рисуем начальное полжение пунктиром
[XInit,YInit]=hinges(q0,l); 
plot(XInit, YInit,'k:'); 

%вычисляем значения углов и рисуем конечное полжение 
[q,fs, e, inf]=fminsearch(@dist,q0, [], l, xc) %,q0) 
[XOptim,YOptim]=hinges(q,l); 
plot(XOptim, YOptim,'k-','LineWidt',2); 

%отрисовываем элементы оформления
plot([0],[-0.3],'k^','MarkerSize',15);
plot(XInit(1:3), YInit(1:3),'ko'); 
plot([XInit(4)], [YInit(4)],'ks', 'MarkerSize', 15); 
plot(XOptim(1:3), YOptim(1:3),'ko'); 
plot([XOptim(4)], [YOptim(4)],'ks', 'MarkerSize', 15); 
xlabel('x1'); ylabel('x2'); 
legend('Начальное','Конечное');
title('Два положения манипулятора'); 
end

function [X,Y] = hinges(q,l)
Q=cumsum(q); 
x=l.*cos(Q); 
y=l.*sin(Q);
x=[0 x]; y=[0 y]; X=cumsum(x); Y=cumsum(y);  
end

