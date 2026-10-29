 /*
     return ((x ^ y) >> 31); //para el caso de 32 bit, quedaría 1 si son diferente
*/    

    //con un xor : 2 numeros iguales tienen que dar 0
    function signosDiferentes(x,y) {
        return ((x ^ y) < 0);  //siempre va a quedar el 1er "1" si signos son diferentes
        
    }
     
    n1=-5; n2=10; //resultado = 6

    console.log(signosDiferentes(n1,n2) );

/*
 
 101= (5 decimal)
 10000010=  -5 

 1010 =10

    1000 0010  (-5)
    0000 1010  (10) 
---------------
    1000 1000


*/