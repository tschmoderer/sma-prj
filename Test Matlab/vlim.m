function v = vlim(v0)

vmx = 2;
if (norm(v0)>vmx) 
v = v0/norm(v0)*rand();
else
v = v0;
end

end
