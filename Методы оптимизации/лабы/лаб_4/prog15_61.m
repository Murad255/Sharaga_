function prog15_61

%отображаем ƒекардовую систему координат в пределах 
%[-1.5; 2.5] по X и [-1.5; 2.5] по Y и настаиваем вывод
axes('Xlim',[-1.5 2.5], 'Ylim',[-1.5 2.5]); 
axis equal; grid off; hold on;
xlabel('x1'); ylabel('x2');
colormap copper;
%формирует массивы X и Y, которые определ€ют координаты узлов
X0=-1.5:0.05:2.5;
[X, Y]=meshgrid(X0);

%вычисление высот точек на  граффике
s=size(X); Z=zeros(s);
for i=1:s(1)
    for j=1:s(2)
        Z(i,j) = Descartes([X(i,j); Y(i,j)]);
    end
end
V=-0.8:0.2:1;
contour(X,Y,Z,V);
%расчитываем минимум функции, а так же дополнительные параметры
Options=optimset('Display', 'final','GradObj', 'on', 'Hessian', 'on');
x0=[2; 2];
[x,fval,eflag,out,grad, Hes]= fminunc(@Descartes,x0,Options)

%рисует линию между точкой x0 и минимумом х
line(x0(1),x0(2), 'Marker', '.', 'MarkerSize', 10); 
line(x(1), x(2), 'Marker', '.', 'MarkerSize', 20);
%отрисовка граффиков
plot([x0(1),x(1)], [x0(2),x(2)],'k-')
end

   function [f,g,H] = Descartes(x)
        f = x(1)^3+x(2)^3-3*x(1)*x(2);
        if nargout > 1
            g = [3*(x(1)^2-x(2)); 3*(x(2)^2-x(1))];
        end
        if nargout > 2
            H = [6*(x(1)) -3; -3 6*(x(2))] ;
        end
   end
