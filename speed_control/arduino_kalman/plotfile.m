clc
clear
%close all
fid1 = fopen('Z.txt','rt');
fid2 = fopen('Z_K.txt','rt');

z=fscanf(fid1,'%f\n');
zk=fscanf(fid2,'%f\n');

fclose(fid1);
fclose(fid2);
figure;
plot(z,'.');hold on;plot(z);hold on;
plot(zk,'r.');hold on;plot(zk,'r');hold on;