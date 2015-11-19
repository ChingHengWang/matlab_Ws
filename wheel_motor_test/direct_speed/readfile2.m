clc
clear
close all
fid1 = fopen('speed.txt','rt');
fid2 = fopen('enc.txt','rt');

actual=fscanf(fid1,'%f\n',498);
enc=fscanf(fid2,'%f\n',498);

fclose(fid1);
fclose(fid2);
figure;
plot(actual,'.');hold on;plot(actual);hold on;
plot(enc,'r.');hold on;plot(enc,'r');hold on;