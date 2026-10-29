   
        a=45; b=10; //resultado = 6
        a = a ^ b
        b = a ^ b
        a = a ^ b
        console.log(a,b);  //siempre va a quedar el 1er "1" si signos son diferentes
        
    
     
    

    

/*
 
 101= (5 decimal)
 10000010=  -5 
 1010 =10


a = a ^ b
b = a ^ b
a = a ^ b


    1000 0010  (-5) a
    0000 1010  (10) b 
---------------
    1000 1000       a



    1000 1000      a
    0000 1010      b
    ----------
    1000 0010  -5  b

    
    1000 1000  a
    1000 0010  b
    ----------
    0000 1010  a 







*/