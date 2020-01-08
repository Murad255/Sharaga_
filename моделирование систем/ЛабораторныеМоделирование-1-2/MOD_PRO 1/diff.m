%Van-der-Pole
x=[];
x0=[0 0.25]';
[t,X]=ode23('vdpol',[0 20],x0);
plot(t,X);
grid
gtext('x1'), gtext('x2')
pause;
clf,close;
