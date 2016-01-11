function M=rotz(th)
%th=th*0.0175;%pi/180;
M=[ cos(th)    -sin(th)        0       0;
    sin(th)     cos(th)        0       0;
          0           0        1       0;
          0           0        0       1;

];
