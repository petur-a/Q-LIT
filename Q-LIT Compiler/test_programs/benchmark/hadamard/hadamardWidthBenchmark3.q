def q = qbit(|1>);

def c = qcirc(4,1);

c.attach(q);

c.add(0,[0],hadamard);
c.add(1,[0],hadamard);
c.add(2,[0],hadamard);
c.add(3,[0],hadamard);