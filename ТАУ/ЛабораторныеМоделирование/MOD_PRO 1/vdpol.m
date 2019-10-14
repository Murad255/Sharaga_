function xdot = vdpol(t,x)
% Van der Pole eq.
% Evaluating of right parts of equations.
xdot = [x(2); x(2).*(1-x(1).^2)-x(1)];


