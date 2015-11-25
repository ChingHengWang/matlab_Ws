clc
clear
fid1 = fopen('acutal.txt','rt');
fid2 = fopen('target.txt','rt');
fid3 = fopen('dT.txt','rt');


actual=fscanf(fid1,'%f\n',300);
target=fscanf(fid2,'%f\n',300);
dT=fscanf(fid3,'%f\n',300);
error=target-actual;

fclose(fid1);
fclose(fid2);
fclose(fid3);
figure;
plot(actual,'.');hold on;plot(target,'.r');grid on;plot(error,'.k');
plot(actual);hold on;plot(target,'r');grid on;plot(error,'k');
mean_err=mean(error(150:300))