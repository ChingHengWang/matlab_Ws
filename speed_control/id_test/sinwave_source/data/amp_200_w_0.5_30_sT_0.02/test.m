close all;
w=0.5;

figure;
for wave=0:1:50;


%w=0.5*(1+floor(25*log(0.05*wave+1)));
w=1*6*log(0.1*wave+1);
plot(wave,w,'*');hold on;
end

