a_max=4/6;
duration_t=0:0.1:6;
sz=size(duration_t);
sz=sz(2);
i=1;
for i=1:sz
    
  if(duration_t(i)<=3)
    a(i)=duration_t(i)*(a_max/3);
  else
    a(i)=a_max-(duration_t(i)-3)*(a_max/3);
  end
end