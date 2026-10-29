/*
 xor =  or - and
     = ((x | y) - (x & y))
*/    

    function xor(x,y) {
        return ((x | y) - (x & y)); 
        
    }
     
    n1=5; n2=3; //resultado = 6

    console.log(xor(n1,n2) );

/*
 


101
 11  xor
---
110
------------------
101
 11  or
---
111


101 and
 11
---
001 

 111
-001
----
 110



*/