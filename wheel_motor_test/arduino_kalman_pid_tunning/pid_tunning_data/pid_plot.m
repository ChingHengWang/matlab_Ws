clc
clear
close all
fid1 = fopen('kp_term.txt','rt');
fid2 = fopen('ki_term.txt','rt');
fid3 = fopen('kd_term.txt','rt');
fid4 = fopen('feedback.txt','rt');
p=fscanf(fid1,'%f\n');
i=fscanf(fid2,'%f\n');
d=fscanf(fid3,'%f\n');
f=fscanf(fid4,'%f\n');
fclose(fid1);
fclose(fid2);
fclose(fid3);
fclose(fid4);



N=length(p);% samples
Fs=50;%50Hz
Ts=0.02;
t=Ts*(1:N);



%figure;plot(pwm_input);
figure;plot(t,p);
figure;plot(t,i);
figure;plot(t,d);
figure;plot(t,f);