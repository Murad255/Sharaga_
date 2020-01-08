%Oscillation of two-mass sistem
%Working file
z=[];
z0=[0 0 9.8*m1 9.8*m2 .5 1 f1 f2 a1 a2 w1 w2 m1 m2 cw c1 c2 j];
options=odeset('OutputFcn','odeplot','Outputsel',[5 6])
%options=odeset('Outputsel',[5 6])
[t,Z]=ode23('vdlabw',[0 20],z0,options);
pause
clf,close;
