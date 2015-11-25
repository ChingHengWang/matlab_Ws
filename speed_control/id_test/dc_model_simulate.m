%{
DC model Identification
Bode plot

Transfer function:
       10
-----------------
(1+1.312s)^2
%}
%close all;
num=[0.002];
den=[15.84 3.185 1];
G=tf(num,den)
s=tf('s');
Kp=50;Ki=50;Kd=3;
C=Kp+Ki/s+Kd*s;
T=feedback(C*G,1);%T=(CG)/(1+CG)
step(T); %observe step response
%figure;bode(g);
