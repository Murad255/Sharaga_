%Oscillation of two-mass sistem
%Working file
z=[];
z0=[0.5 0];
options=odeset('OutputFcn','odeplot','Outputsel',[1 2])
%options=odeset('Outputsel',[1 2])
[t,Z]=ode23('du',[0 10],z0,options);
pause
clf,close;