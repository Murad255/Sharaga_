% M-file approk
for j=2:15
    x=60:0.5:120;
    p=polyfit(x,y,j)
    f=polyval(p,x);
    plot(x,y,'ob',x,f,'-g')
pause
end
clf,close;
