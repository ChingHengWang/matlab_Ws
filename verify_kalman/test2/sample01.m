clc
clear
%close all
fid1 = fopen('data1.txt','rt');


raw=fscanf(fid1,'%f\n');
%raw=fscanf(fid2,'%f\n');
%filter=fscanf(fid3,'%f\n');
fclose(fid1);

%plot frequency figure
N=length(raw);% samples
Fs=10;%10Hz
Ts=0.1;
t=Ts*(1:N);
Y=fft(raw,N)/length(raw); 
f=Fs/2*linspace(0,1,N/2); 
plot(f,2*abs(Y(1:N/2))) 



%plot time domain raw data
%figure;
plot(t,raw,'b.');
hold on;

lf_data_0=150;
a=0.2;
for i=1:1:N
    
    if (i==1)
        lf_data(1)=(a)*raw(i)+(1-a)*lf_data_0;
    else    
        lf_data(i,:)=(a)*raw(i)+(1-a)*lf_data(i-1);
    end

end


hold on;
plot(t,lf_data,'r');
hold on;






%title('kp80ki5kd0.2_interpolation');axis([0 25 -0.5 3]);

X=[150;0];
P=[1 0;0 1];
F=[1 0.1;0 1];
Q=[0.1 0;0 0.1];
H=[1 0];
R=500;

for i=1:1:N
X_=F*X;
P_=F*P*F'+Q;
K=P_*H'/(H*P_*H'+R);
X=X_+K*(raw(i)-H*X_);
P=(eye(2)-K*H)*P_;
kalman(i,1)=X(1);
end


plot(t,kalman,'k.');
