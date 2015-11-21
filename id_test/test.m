%{
Nyquist plot
Bode plot

Transfer function:
       10
-----------------
s^3 + 3 s^2 + 2 s
%}

num=[10];
den=[1 3 2 0];
g=tf(num,den)
figure;
nyquist(g);
figure;
bode(g);