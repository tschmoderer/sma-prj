function [vx,vy] = bound(p)

px = p(1);
py = p(2);
vx = 0;
vy = 0;

if px < -1 
vx = 0.02;
elseif px > 1
vx = -0.02;
end

if py < -1
vy = 0.02;
elseif py > 1 
vy = -0.02;
end

end