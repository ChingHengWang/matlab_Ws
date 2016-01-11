function M=rotx(th)
%th=th*0.0175;%pi/180;
M=[ 1       0       0       0;
    0 cos(th) -sin(th)      0;
    0 sin(th)  cos(th)      0;
    0       0       0       1;

];
