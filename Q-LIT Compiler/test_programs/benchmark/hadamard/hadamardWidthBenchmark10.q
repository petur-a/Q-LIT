def q = qbit(|1>);

def c = qcirc(11,1);

c.attach(q);

c.add(0,[0],hadamard);
c.add(1,[0],hadamard);
c.add(2,[0],hadamard);
c.add(3,[0],hadamard);
c.add(4,[0],hadamard);
c.add(5,[0],hadamard);
c.add(6,[0],hadamard);
c.add(7,[0],hadamard);
c.add(8,[0],hadamard);
c.add(9,[0],hadamard);
c.add(10,[0],hadamard);