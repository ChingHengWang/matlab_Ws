clc
clear
%close all
fid1 = fopen('target.txt','rt');
fid2 = fopen('actual.txt','rt');

target=fscanf(fid1,'%f\n');
actual=fscanf(fid2,'%f\n');

fclose(fid1);
fclose(fid2);
figure;
plot(target,'.');hold on;plot(target);hold on;
plot(actual,'.r');hold on;plot(actual,'r');hold on;