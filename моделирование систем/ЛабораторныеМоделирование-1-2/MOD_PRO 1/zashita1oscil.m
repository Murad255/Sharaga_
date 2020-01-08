%Oscillation of two-mass sistem
%Working file
z=[];
z0=[0 1];
options=odeset('OutputFcn','odeplot','Outputsel',[2])
[t,z]=ode45('zashita1',[0 1],z0,options);
pause
clf,close;