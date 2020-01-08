% M-file approk
for j=2:15
    x=0:.03*pi:pi;
    p=polyfit(x,y,j)
    f=polyval(p,x);
    plot(x,y,'ob',x,f,'-g')
pause
end
clf,close;
