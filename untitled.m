N=length(Chirp.signals.values);% samples
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
PWM_INPUT=abs(fft(Chirp.signals.values));
PWM_INPUT=PWM_INPUT(1:N/2);

%figure;plot(pwm_input);
figure;plot(f,20*log(PWM_INPUT));
figure;plot(t,Chirp.signals.values);
