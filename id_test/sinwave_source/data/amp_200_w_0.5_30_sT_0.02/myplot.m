clc
clear
%close all
fid1 = fopen('sin_frequency_input.txt','rt');
fid2 = fopen('pwm_input.txt','rt');
fid3 = fopen('angular_speed_output.txt','rt');

sin_frequency_input=fscanf(fid1,'%f\n');
pwm_input=fscanf(fid2,'%f\n');
angular_speed_output=fscanf(fid3,'%f\n');
fclose(fid1);
fclose(fid2);
fclose(fid3);
%figure;plot(sin_frequency_input,'.');hold on;plot(sin_frequency_input);hold on;
%figure;plot(pwm_input,'.');hold on;plot(pwm_input,'b');hold on;
%figure;plot(angular_speed_output,'.');hold on;plot(angular_speed_output,'b');





N=length(pwm_input);% samples
Fs=50;%50Hz
Ts=0.02;
t=Ts*(1:N);
PWM_INPUT=abs(fft(pwm_input));
PWM_INPUT=PWM_INPUT(1:N/2);
f=Fs*[0:N/2-1]/N;
%figure;
%plot(Datf);
figure;plot(f,PWM_INPUT);