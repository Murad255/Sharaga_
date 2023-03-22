function prog15_4
line([-2,-eps],[g(-2),g(-eps)]);
hold on; grid off;
line([eps,2],[g(eps),g(2)]);
xlabel('x'); ylabel('y');
[x,f]=fminbnd(@g,-2,2)
line(x,f, 'Marker', '.', 'MarkerSize', 20);
function y=g(x)
if x>0
y=-x-1;
else
 y=x+1;
end