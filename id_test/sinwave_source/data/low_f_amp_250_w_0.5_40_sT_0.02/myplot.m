clc
clear
close all
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
f=Fs*[0:N/2-1]/N;
%{
ff = linspace(1,25,N);
x = sin(ff .* (2*pi*t));
X=abs(fft(x));
%X=X(1:N/2);
figure;plot(X);
%}
PWM_INPUT=abs(fft(pwm_input));
PWM_INPUT=PWM_INPUT(1:N/2);

%figure;plot(pwm_input);
figure;plot(f,20*log(PWM_INPUT));
figure;plot(t,pwm_input);
figure;plot(t,angular_speed_output);
OUTPUT=abs(fft(angular_speed_output));
OUTPUT=OUTPUT(1:N/2);

%figure;plot(pwm_input);
figure;plot(f,20*log(OUTPUT));

figure;plot(log(f),20*log((OUTPUT)./((PWM_INPUT))));
