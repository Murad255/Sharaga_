function zpart=vdlab(t,z)
%Execute right parts
zpart=[(z(7)+9.8*z(13)-z(3)-z(18)*(z(1)-z(2))+z(15)*(0.75-z(6))*sgm(0.75,z(6)))/z(13);
       %proizvodnaja v1
       (z(8)+9.8*z(14)+z(3)+z(18)*(z(1)-z(2))-z(4)-z(18)*z(2)-z(15)*(z(5)-0.75)*sgm(z(5),0.75))/z(14);
       %proizvodnaja v2
       z(16)*(z(1)-z(2)); z(17)*z(2);
       %proizvodnaja Fu1; Fu2
       z(2); z(1); 
       %proizvodnaja x2; x1
       z(9)*cos(z(11)*t); z(10)*cos(z(12)*t); 
       %skorosti izmenenija vneshnix sil F1; F2
       0;0;0;0;0;0;0;0;0;0]; 
       %ystanovka konstant
