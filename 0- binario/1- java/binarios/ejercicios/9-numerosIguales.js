
 /*
 xor =  or - and
     = ((x | y) - (x & y))

 
 


*/    

    //con un xor : 2 numeros iguales tienen que dar 0
    function igualdad(x,y) {
        if ((x ^ y) != 0) {   //if ((x & ~y) == 0 && (~x & y) == 0)
            return('diferentes');
        } else {
            return('iguales');
        }
        
    }
     
    n1=5; n2=5; //resultado = 6

    console.log(igualdad(n1,n2) );

/*
 


*/