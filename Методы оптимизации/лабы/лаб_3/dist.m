
function d=dist(q,l,xc) %,q0) 
    x=coord(q,l); 
    d=norm(x-xc);%+norm(q);
end
 
function x=coord(q,l) 
Q=cumsum(q); 
x=[sum(l.*cos(Q)); sum(l.*sin(Q))]; 
end
