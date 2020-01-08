>> y=[];
>> y=exp(sin(x));
>> approk% M-file peetals 
theta=-pi:0.01:pi;
rho(1,:)=2*sin(5*theta).^2;
rho(2,:)=cos(10*theta).^3;
rho(3,:)=sin(theta).^2;
rho(4,:)=rho(1,:)+rho(3,:);
for i=1:4
   plot(theta, rho(i,:))
   pause
end
clf,close
