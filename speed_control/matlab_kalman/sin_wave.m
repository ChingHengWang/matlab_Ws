close all;



X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[0.00001 0;0 0.00001];
H=[1 0];
R=1;
figure;
omega_actual=0;
for i=1:2000
    if(i>200)
        omega_actual=5*sin(0.2*((i-200)*0.02))+(mod(randn(1,1),0.6)-0.3);
    end

    if(i>=1771)
        omega_actual=0+(mod(randn(1,1),0.6)-0.3);
    end
    X_=F*X;
    P_=F*P*F'+Q;
    K=P_*H'/(H*P_*H'+R);
    X=X_+K*(omega_actual-H*X_);
    P=(eye(2)-K*H)*P_;
    omega_actual_filter=X(1);
    plot(i,omega_actual,'*');hold on;
    plot(i,omega_actual_filter,'r*');hold on;
   
end

