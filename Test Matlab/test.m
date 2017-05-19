clc
clear all
close all

NbBoid = 4; 
niter = 10;

%boid : matrice 4*NbBoid
%boid(1:2,k) : vecteur position de l'oiseau k
%boid(3:4,k) : vecteur vitesse de l'oiseau k

%Initialisation
boid = double([0,0,0,0;0.5,0,0,0;0,0.5,0,0;0.5,0.5,0,0])';

%plot(boid(1,:),boid(2,:),'*')
%axis([-1 1 -1 1])
%pause(2);


for k=1:niter
for j=1:NbBoid
[v1,v2,v3] = rules(NbBoid,boid,j);
[vx,vy] = bound(boid(1:2,j));
v4 = [vx,vy]';
v = v1+v2+v3+v4;
boid(3:4,j) = vlim(boid(3:4,j) + v);
boid(1:2,j) = boid(1:2,j) + boid(3:4,j);
end
%pause(0.2);
%draw(boid);
%axis([-3 3 -3 3])
end
boid