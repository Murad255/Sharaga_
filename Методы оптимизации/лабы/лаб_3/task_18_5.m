function task_18_5
axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on; 
l=0; %заглушка
xc=[5; 5];     
q0=[1.5 0.7 1.5];  

[XInit,YInit]=hinges(q0,l); 
plot(XInit, YInit,'k:'); 
qOptim=fminsearch(@dist,q0, [], l, xc) 
[XOptim,YOptim]=hinges(qOptim,l); 
plot(XOptim, YOptim,'k-','LineWidt',2); 

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
x=[q(2)*cos(q(1))  q(3)*sin(q(1))]; 
y=[q(2)*sin(q(1)) -1*q(3)*cos(q(1))]; 
x=[0 x]; y=[0 y];
X=cumsum(x); Y=cumsum(y); 
end

function x=coord(q,l) 
x1=q(2)*cos(q(1))+ q(3)*sin(q(1)); 
y1=q(2)*sin(q(1)) -1*q(3)*cos(q(1)); 
x=[x1; y1]; 
end

function d=dist(q,l,xc) 
    x=coord(q,l); 
    d=norm(x-xc);
end
