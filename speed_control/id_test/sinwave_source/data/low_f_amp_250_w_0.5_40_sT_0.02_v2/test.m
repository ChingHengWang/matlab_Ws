close all;
w=0.5;

figure;
for wave=0:1:500;


%w=0.5*(1+floor(25*log(0.05*wave+1)));
w=1*floor(5*log(0.4*wave+1.3));
plot(wave,w,'*');hold on;
end

