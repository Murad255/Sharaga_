
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