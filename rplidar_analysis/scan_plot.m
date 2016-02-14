clc
clear
close all
fid1 = fopen('data.txt','rt');

scan=fscanf(fid1,'%f,\n');
%filter=fscanf(fid3,'%f\n');
fclose(fid1);
%plot frequency figure
N=length(scan);% samples
angle=3.14:-0.01745:-3.14;
angle=0:0.01745:6.28;
test=0:1:359;
angle=angle';
figure;
%plot time domain raw data
%figure;
polar(angle,scan,'.');
figure;
plot(scan);