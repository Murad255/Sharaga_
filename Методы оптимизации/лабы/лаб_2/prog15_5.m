function prog15_5 
X0=-1:0.1:3; 
Y0=-1:0.1:5; 
[X, Y]=meshgrid(X0,Y0); s=size(X); Z=zeros(s); 
for i=1:s(1)     
    for j=1:s(2) 
        Z(i,j) = Rosenbrock([X(i,j); Y(i,j)]);    
    end
end
axes('Xlim',[-3 3], 'Ylim',[-2 5]);
axis equal; grid off; hold on;
v=1:2:10; V=10:4:20; 
contour(X,Y,Z,[v V]);
xlabel('x1'); ylabel('x2');
x0=[2; 1];
line(x0(1),x0(2), 'Marker', '.', 'MarkerSize', 10); 
[x,f]= fminsearch('x(1)^2+x(1)*x(2)+x(2)^2-4*log(x(1))-10*log(x(2))', x0) 
line(x(1),x(2), 'Marker', '.', 'MarkerSize', 20); 
 
plot([x0(1),x(1)], [x0(2),x(2)],'k-') 
end