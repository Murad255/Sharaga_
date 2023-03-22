function z=discont(x)
if (x(1)> 0) & (x(2) >= 0)  
    z = x(1)+2*x(2); 
elseif (x(1)<= 0) & (x(2) >= 0)
    z = -2*x(1)+x(2); 
elseif (x(1)< 0) & (x(2) <= 0) 
    z = -x(1)-2*x(2); 
elseif (x(1)>= 0) & (x(2) < 0)  
    z = 2*x(1)-x(2); 
elseif (x(1)== 0) & (x(2) == 0) 
    z = 0;
end 
