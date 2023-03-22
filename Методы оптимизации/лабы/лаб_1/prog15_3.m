function prog15_3
xx=-2:0.1:3;
yy=fun(xx);
plot(xx,yy,'k-')
hold on; grid;
xlabel('x'); ylabel('y');
[x,f]=fminbnd(@fun,-2,0)
line(x,f, 'Marker', '.', 'MarkerSize', 20);
[x,f]=fminbnd(@fun,0,3)
line(x,f, 'Marker', '.', 'MarkerSize', 20);
end
function y=fun(x)
y= 3*x.^4-4*x.^3-12*x.^2;
end
