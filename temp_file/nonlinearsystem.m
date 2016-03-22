theta=1:0.0001:10;

plot(sin(theta));
hold on;
plot(theta-(1/2)*theta.^2);