close all;



X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[0.0001 0;0 0.0001];
H=[1 0];
R=1;
figure;
omega_actual=0;
for i=1:1200
    if(i>200)
        omega_actual=5+(mod(randn(1,1),0.4)-0.2);
    end
    %{
    if (i>=780)
        omega_actual=4+(mod(randn(1,1),0.2)-0.1);
    end
    if (i>=795)
        omega_actual=2+(mod(randn(1,1),0.2)-0.1);
    end
    %}
    if(i>=850)
        omega_actual=0+(mod(randn(1,1),0.4)-0.2);
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
title('trust observation most, estimate >30 times');




X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[100 0;0 100];
H=[1 0];
R=100;
figure;
omega_actual=0;
for i=1:1200
    if(i>200)
        omega_actual=5+(mod(randn(1,1),0.4)-0.2);
    end
    %{
    if (i>=780)
        omega_actual=4+(mod(randn(1,1),0.2)-0.1);
    end
    if (i>=795)
        omega_actual=2+(mod(randn(1,1),0.2)-0.1);
    end
    %}
    if(i>=850)
        omega_actual=0+(mod(randn(1,1),0.4)-0.2);
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
title('more trust observation, ~= 4 times');



X=[0;0];
P=[1 0;0 1];
F=[1 1;0 1];
Q=[70 0;0 70];
H=[1 0];
R=1000;
figure;
omega_actual=0;
for i=1:1200
    if(i>200)
        omega_actual=5+(mod(randn(1,1),0.4)-0.2);
    end
    %{
    if (i>=780)
        omega_actual=4+(mod(randn(1,1),0.2)-0.1);
    end
    if (i>=795)
        omega_actual=2+(mod(randn(1,1),0.2)-0.1);
    end
    %}
    if(i>=850)
        omega_actual=0+(mod(randn(1,1),0.4)-0.2);
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
title('trst observation but enlarge nosie size, estimate ~=6 times');
