//posicion del bit NO establecido más a la derecha
//Para encontrar el bit no establecido, invierto la busqueda del bit establecido

    function setBitNumber(n)
    {
        

        let bit = parseInt(Math.log2(~n & -~n)+1)
        return bit
        
    }
     
    let n = 10;
    console.log(setBitNumber(n));
