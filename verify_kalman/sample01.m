clc
%clear
%close all
fid1 = fopen('t.txt','rt');
fid2 = fopen('raw.txt','rt');
fid3 = fopen('filter.txt','rt');

%t=fscanf(fid1,'%f\n');
%raw=fscanf(fid2,'%f\n');
%filter=fscanf(fid3,'%f\n');
fclose(fid1);
fclose(fid2);
fclose(fid3);



N=length(t);% samples
%Fs=50;%50Hz
%Ts=0.02;
%t=Ts*(1:N);



%figure;plot(pwm_input);
figure;
plot(t,raw,'b');
hold on;
plot(t,filter,'r');
hold on;
%title('kp80ki5kd0.2_interpolation');axis([0 25 -0.5 3]);

X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[0.0001 0;0 0.0001];
H=[1 0];
R=0.4;

for i=1:1:N
X_=F*X;
P_=F*P*F'+Q;
K=P_*H'/(H*P_*H'+R);
X=X_+K*(raw(i)-H*X_);
P=(eye(2)-K*H)*P_;
kalman(i,1)=X(1);
end


plot(t,kalman,'k');
