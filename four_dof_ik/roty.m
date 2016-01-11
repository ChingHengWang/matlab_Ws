function M=roty(th)
%th=th*0.0175;%pi/180;
M=[ cos(th)     0       sin(th)     0;
    0           1       0           0;
    -sin(th)    0       cos(th)     0;
    0           0       0           1;
];
