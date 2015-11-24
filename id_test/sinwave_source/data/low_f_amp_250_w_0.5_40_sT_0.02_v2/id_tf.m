%{
dc motor tf
Transfer function:
       0.0032
-----------------
1 s^2 + 2 s +1
%}

num=[0.0032];
%den=[1 3 2 0];
den=[1 2 1];
g=tf(num,den)
%figure;nyquist(g);
figure;
bode(g);

