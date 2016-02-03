clc
clear
close all
fid1 = fopen('data.txt','rt');
fid2 = fopen('filter_data.txt','rt');


raw=fscanf(fid1,'%f\n');
filter_raw=fscanf(fid2,'%f\n');
%filter=fscanf(fid3,'%f\n');
fclose(fid1);
fclose(fid2);
%plot frequency figure
N=length(raw);% samples
Fs=10;%10Hz
Ts=0.1;
t=Ts*(1:N);
Y=fft(raw,N)/length(raw); 
f=Fs/2*linspace(0,1,N/2); 
plot(f,2*abs(Y(1:N/2))) ;


figure;
%plot time domain raw data
%figure;
plot(t,raw,'b.');hold on;
plot(t,filter_raw,'r.');
axis([0 10 0 400]);
grid on;


