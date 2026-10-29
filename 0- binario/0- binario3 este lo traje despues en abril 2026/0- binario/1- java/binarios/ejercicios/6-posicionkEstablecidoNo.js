//Compruebe si el K-th bit está establecido o no
    function setBitNumber(n,k)
    {
        
        return Math.log2(n)+1

        //let bit = parseInt(Math.log2(~n & -~n)+1)
        //return bit
        
    }
     
    let n = 16; //1100111
    let k=3

    console.log(setBitNumber(n,k) );

/*
  10000 (16) 
 1111 (15)

*/