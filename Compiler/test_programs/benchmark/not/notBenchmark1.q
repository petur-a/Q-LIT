def q = qbit(|11>);

def c = qcirc(1,2);

c.attach(q);

c.add(0,[0],not);
c.add(0,[1],not);