%{
dc motor tf
Transfer function:
       0.05
-----------------
  (1+3.3s)^2
%}

num=[0.05];
%den=[10.89 6.66 1];
den=[10.89 6.66 1];
g=tf(num,den)
%figure;nyquist(g);
figure;
bode(g);

