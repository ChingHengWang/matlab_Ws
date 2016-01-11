clc
clear
%close all
fid1 = fopen('target.txt','rt');
fid2 = fopen('feedback.txt','rt');

target=fscanf(fid1,'%f\n');
feedback=fscanf(fid2,'%f\n');
fclose(fid1);
fclose(fid2);
%figure;plot(sin_frequency_input,'.');hold on;plot(sin_frequency_input);hold on;
%figure;plot(pwm_input,'.');hold on;plot(pwm_input,'b');hold on;
%figure;plot(angular_speed_output,'.');hold on;plot(angular_speed_output,'b');





N=length(target);% samples
Fs=50;%50Hz
Ts=0.02;
t=Ts*(1:N);



%figure;plot(pwm_input);
figure;plot(t,target,'r');
hold on;plot(t,feedback);hold on;plot(t,feedback,'.')
title('kp20ki0kd0_interpolation');axis([0 25 -0.5 3]);
