clc
clear
%close all

%%%%% SETTING XYZ %%%%%%%%%%%%%%%%%%
t=0;T=300;
x=T*sin(t);y=-T*cos(t);z=-150;L1=235;L2=250;

x=300;y=300;z=0;
%syms x y z L1 L2
%syms th1 th2 th3 th4
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

p=[x y z]; 
norm(p)
th4=pi-acos((L1^2+L2^2-norm(p)^2)/(2*L1*L2))
a=asin(L2/norm(p))*sin(th4);
%%%%%%% s is shoulder point
s=[0 0 0];
unit_z=[0 0 1];

%%%%%% create unit vector of shoulde to EndEffect p
tmp=p-s;
norm_p_s=(tmp(1)^2+tmp(2)^2+tmp(3)^2)^0.5;
unit_n=(p-s)/norm_p_s

%%%%%% create u and v , these are orthogonal to unit_n
unit_u=(unit_z+dot(unit_z,unit_n)*unit_n)
unit_v=cross(unit_n,unit_u)

%%%%%%% c is center of elbow circle 
c=s+cos(a)*L1*unit_n;

%%%%%% ri is radius of elbow circle
r=L1*sin(a);

%%%%% choose fi to decide whice point is elbow
fi=pi/2;

%%%%% decide elbow point e
e=c+r*(cos(fi)*unit_u+sin(fi)*unit_v)
ex=e(1);ey=e(2);ez=e(3);

%%%%% use elbow point to find th0 and th1
if(ex>=0&&ey<0)
    th1=atan(abs(ex)/abs(ey));
else if (ex>=0&&ey>=0)
        th1=pi-atan(abs(ex)/abs(ey));
    else if (ex<0&&ey>=0)
            th1=pi+atan(abs(ex)/abs(ey));
        else if (ex<0&&ey<0)
                  th1=-atan(abs(ex)/abs(ey));    
            end
        end
    end
end
if(ez>=0)
th2=-atan(abs(ez)/(ex^2+ey^2)^0.5);
else if(ez<0)
  th2=atan(abs(ez)/(ex^2+ey^2)^0.5);
    end
end

%syms x y z th1 th2 th3 th4 L1 L2 
%Fr0_T_Fr1=rotz(th1);
%Fr1_T_Fr2=rotx(-pi/2)*rotx(th2);
%Fr2_T_Fr3=tranz(-L1)*rotz(th3);
%Fr3_T_Fr4=roty(-th4)*tranz(-L2);



c1=cos(th1);s1=sin(th1);c2=cos(th2);s2=sin(th2);

th3=atan2(-x*s1*s2+y*c1*s2-z*c2,x*c1+y*s1)

c3=cos(th3);s3=sin(th3);c4=cos(th4);s4=sin(th4);

Fr0_T_Fr1=[c1 -s1 0 0;s1 c1 0 0;0 0 1 0;0 0 0 1];
Fr1_T_Fr2=[1 0 0 0;0 s2 c2 0;0 -c2 s2 0;0 0 0 1];
Fr2_T_Fr3=[c3 -s3 0 0;s3 c3 0 0;0 0 1 -L1;0 0 0 1];
Fr3_T_Fr4=[c4 0 -s4 L2*s4;0 1 0 0;s4 0 c4 -L2*c4;0 0 0 1];


Fr0_T_Fr3=Fr0_T_Fr1*Fr1_T_Fr2*Fr2_T_Fr3;
%Fr0_T_Fr3*[0 0 0 1]'
Fr0_T_Fr4=Fr0_T_Fr1*Fr1_T_Fr2*Fr2_T_Fr3*Fr3_T_Fr4
%inv(Fr0_T_Fr1*Fr1_T_Fr2)*[x ;y ;z ;1]
%Fr2_T_Fr3*Fr3_T_Fr4*[0 ;0 ;0 ;1]
E=[Fr0_T_Fr4(1,4) Fr0_T_Fr4(2,4) Fr0_T_Fr4(3,4)];

plot3([o(1) e(1)],[o(2) e(2)],[o(3) e(3)]);hold on;plot3([e(1) E(1)],[e(2) E(2)],[e(3) E(3)],'r');grid on;
axis([-500,500,-500,500,-500,500]);view(0,-180);
x
y
z
th1
th2
th3
th4
norm_p=norm(p)
