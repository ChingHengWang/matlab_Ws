%kalman_filter




enc_pre=0;

for i=1:1:498
    %v(i)=((enc(i)-enc_pre)*2*pi)/ ((52*65.5)* 0.02);
    enc_v(i)=(enc(i)-enc_pre)/1;
    enc_pre=enc(i);
end

plot(enc_v,'*');hold on;
plot(enc_v);hold on;
X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[0.0001 0;0 0.0001];
H=[1 0];
R=1;


for i=1:170
    X_=F*X;
    P_=F*P*F'+Q;
    K=P_*H'/(H*P_*H'+R);

    X=X_+K*(enc(i)-H*X_);
    P=(eye(2)-K*H)*P_;
    plot(i,X(2),'*r');hold on;
    plot(i,X(2),'r');hold on;
    i
    X_
    P_
    K
    enc(i)
    X
    P
end

