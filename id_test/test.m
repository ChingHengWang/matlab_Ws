%{
Nyquist plot
Bode plot

Transfer function:
       10
-----------------
(1+1.312s)^2
%}
%close all;
num=[0.002];
den=[15.84 3.185 1];
G=tf(num,den);
s=tf('s');
Kp=50;
Ki=50;
Kd=3;
C=tf(Kp+Ki/s+Kd*s)

GG=series(C,G)
feedback(Kp+Ki/s+Kd*s,1)
%figure;bode(g);