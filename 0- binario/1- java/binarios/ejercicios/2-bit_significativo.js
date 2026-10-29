
    function setBitNumber(n)
    {
        let Msb = parseInt(Math.log2(n))
        return 1 << Msb;
    }
     
    let n = 256;
      console.log(setBitNumber(n));
/*
      console.log(Math.log(0));
      console.log(Math.log(-5));

      console.log( parseInt(Math.log2(8))  );

      

      console.log(   parseInt(Math.log(3)/Math.log(2),10) ); //  Math.log2(3) = 1.584962500721156
*/
