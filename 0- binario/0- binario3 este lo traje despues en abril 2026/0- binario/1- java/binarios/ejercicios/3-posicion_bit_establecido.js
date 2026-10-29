//posicion del bit establecido más a la derecha
    function setBitNumber(n)
    {
        //return n & -n
        let bit = parseInt(Math.log2(n & -n)+1)
        return bit
        
    }
     
    let n = 103;
    console.log(setBitNumber(n));
