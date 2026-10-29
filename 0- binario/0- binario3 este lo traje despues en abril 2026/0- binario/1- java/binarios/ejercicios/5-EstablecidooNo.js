//Compruebe si el K-th bit está establecido o no
    function setBitNumber(n,k)
    {
        
        return (n & ( 1<<(k) ) )!=0

        //let bit = parseInt(Math.log2(~n & -~n)+1)
        //return bit
        
    }
     
    let n = 103; //1100111
    let k=3

    console.log(setBitNumber(n,k) );
