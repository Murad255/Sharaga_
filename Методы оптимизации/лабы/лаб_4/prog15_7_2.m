function prog15_7_2

axes('Xlim',[-1 15], 'Ylim',[-1 10]); axis equal; grid on; hold on;
l=[5 5 5];
xc=[12; 0];
q0=[0.7 -0.9 0.5];
dq=[-1 1; -1 1; -1 1];
a=transpose(dq(:,1));
b=transpose(dq(:,2));
z0 = [ tan((q0(1) -(a(1) + b(1))/2).* pi/(b(1)-a(1)))
tan((q0(2) -(a(2) + b(2))/2).* pi/(b(2)-a(2)))
tan((q0(3) -(a(3) + b(3))/2).* pi/(b(3)-a(3))) ]
[XInit,YInit]=hinges(q0,l);
plot(XInit, YInit,'k:');
[z,fs, e, inf]=fminsearch(@distz,z0, [], l, xc)
q = [ (b(1) - a(1))/pi.*atan(z(1)) + (a(1) + b(1))/2
(b(2) - a(2))/pi.*atan(z(2)) + (a(2) + b(2))/2
(b(3) - a(3))/pi.*atan(z(3)) + (a(3) + b(3))/2 ]
[XOptim,YOptim]=hinges(transpose(q),l);
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
Q=cumsum(q);
x=l.*cos(Q);
y=l.*sin(Q);
x=[0 x]; y=[0 y];
X=cumsum(x); Y=cumsum(y);
end

function d=distz(z,l,xc)
dq=[-1 1; -1 1; -1 1]; %интервалы перемещений
a=transpose(dq(:,1));
b=transpose(dq(:,2));
%q = (b - a)/pi.*atan(z) + (a + b)/2;
q = [ (b(1) - a(1))/pi.*atan(z(1)) + (a(1) + b(1))/2
(b(2) - a(2))/pi.*atan(z(2)) + (a(2) + b(2))/2
(b(3) - a(3))/pi.*atan(z(3)) + (a(3) + b(3))/2 ];
x=coord(q,l);
d=norm(x-xc);
end

function x=coord(q,l)
Q=cumsum(q);
x=[sum(l.*cos(Q)); sum(l.*sin(Q))];
end 