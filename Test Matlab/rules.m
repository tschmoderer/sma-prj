function [v1,v2,v3] = rules(NbBoid,boid,j)

p = [0;0];
c = [0;0];
q = [0;0];
for i=1:NbBoid
if (i ~= j)
p = p + boid(1:2,i);
q = q + boid(3:4,i);
if (norm(boid(1:2,i)-boid(1:2,j))<0.1 )
c = c-boid(1:2,i)+boid(1:2,j);
endif
endif
end
p = p/(NbBoid-1);
q = q/(NbBoid-1);
v1 = (p-boid(1:2,j))/100.0;
v2 = c/8.0;
v3 = (q-boid(3:4,j))/8.0;
end
