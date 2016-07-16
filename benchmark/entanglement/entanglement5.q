def q = qbit(|00000>);

def c = qcirc(6,5);

c.attach(q);

c.add(0,[0],hadamard);

c.add(1,[0;1],not);
c.add(2,[0;2],not);
c.add(3,[0;3],not);
c.add(4,[0;4],not);

c.add(5,[0],measurement);