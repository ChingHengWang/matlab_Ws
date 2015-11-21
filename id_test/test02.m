%{
Nyquist plot
Bode plot

Transfer function:
       10
-----------------
s^3 + 3 s^2 + 2 s
%}

num=[1];
den=[1 0.1 1];
g=tf(num,den)
figure;
nyquist(g);
figure;
bode(g);