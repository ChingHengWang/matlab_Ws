%kalman_filter
Z=(1:100)+randn(1,100);
figure; 
%plot(Z);




z_pre=0;

for i=1:1:100
    %v(i)=((enc(i)-enc_pre)*2*pi)/ ((52*65.5)* 0.02);
    zv(i)=(Z(i)-z_pre)/1;
    z_pre=Z(i);
end

plot(zv);hold on;

X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[0.0001 0;0 0.0001];
H=[1 0];
R=10000;


for i=1:100
    X_=F*X;
    P_=F*P*F'+Q;
    K=P_*H'/(H*P_*H'+R);
    X=X_+K*(Z(i)-H*X_);
    P=(eye(2)-K*H)*P_;
    plot(i,X(2),'*r');hold on;
end
