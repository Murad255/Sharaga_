function prog10_3
axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on; 
l=[6 6]; 
xc=[12; 0];    
q0=[1 -1 0.5]; 

[XInit,YInit]=hinges(q0,l); 
plot(XInit, YInit,'k:'); 

[q,fs, e, inf]=fminsearch(@dist,q0, [], l, xc) %,q0) 
[XOptim,YOptim]=hinges(q,l); 
plot(XOptim, YOptim,'k-','LineWidt',2); 

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
x=[q(1) l(1)*cos(q(2))  l(2)*cos(q(2)+q(3))]; 
y=[0    l(1)*sin(q(2))  l(2)*sin(q(2)+q(3))]; 
x=[0 x]; y=[0 y];
X=cumsum(x); Y=cumsum(y); 
end

function x=coord(q,l) 
x1=q(1)+l(1)*cos(q(2))+l(2)*cos(q(2)+q(3)); 
y1=l(1)*sin(q(2))+ l(2)*sin(q(2)+q(3)); 
x=[x1; y1]; 
end

function d=dist(q,l,xc) 
    x=coord(q,l); 
    d=norm(x-xc);
end

