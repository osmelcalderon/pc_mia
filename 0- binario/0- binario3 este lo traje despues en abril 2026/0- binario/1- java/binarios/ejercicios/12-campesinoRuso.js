/*
¿Cómo funciona esto?  
 - El valor de a*b es el mismo que (a*2)*(b/2) si b es par;       3 y 6
 - De lo contrario, el valor es el mismo que ((a*2)*(b/2) + a).   3 y 5

En el bucle while, seguimos multiplicando 'a' por 2 y dividiendo 'b' entre 2.
Si 'b' se vuelve impar en el bucle, sumamos 'a' a 'res'. 
Cuando el valor de 'b' se convierte en 1, el valor de 'res' + 'a'
     nos da el resultado. 

Tenga en cuenta que cuando 'b' es una potencia de 2, la 'res' permanecería en 0 
y 'a' tendría la multiplicación. 


    mientra b>0 {
        if (b es impar) {
           res = res + a; 
        }   
        desplazamos "A" a la izquierda a = a << 1;
        desplazamos "B" a la Derecha   b = b >> 1;
    }    
    return res;

111 = 7
011 = 3
001 = 1
000 = 0



*/
function desplazarDerecha(a,b)
{
    while (b > 0)
    {
        if (b & 1) 
            console.log("a:",a);
        
        console.log(b);
        a = a << 1;
        b = b >> 1;
        
    }
    //return res;
}

console.log(desplazarDerecha(10,9)); 

function russianPeasant(a, b)
{
    var res = 0; // inicializar resultado
 
    // Mientras que el segundo número no se convierte en 1
    while (b > 0)
    {
     
        // Si el segundo número se vuelve impar, sumamos el primer número al resultado
        if (b & 1) 
            res = res + a; 
 
        // Duplicar el primer número y reducir a la mitad el segundo número
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
 


console.log(11 & 1); // 1011(11) & 0001 = 1(true) 
console.log(10 & 1); // 1010(10) & 0001 = 0(false)

//////////////////////////////////
 //a= 18 y b=1
        //10010       18 
        //100100     18<<1
                    res=18

        //001        1
        //000        1>>1

//////////////////////////////////
 //a= 18 y b=2
        //10010       18 
        //100100     18<<1
                        

        //010        2
        //001        2>>1



        
        //100100     36<<1

        //010        2
        //001        2>>1




console.log(russianPeasant(9, 9) );
console.log(russianPeasant(20, 12));



function dividir(a, b)
{
    var res; // = a; // inicializar resultado
 
    // Mientras que el segundo número no se convierte en 1
    while (b > 1)
    {
     
        // Si el segundo número se vuelve impar, sumamos el primer número al resultado
        if (b & 1) 
            res =a; // res - a; 
 
        // Duplicar el primer número y reducir a la mitad el segundo número
        a = a >> 1;
        b = b >> 1;
    }
    return a;
}
console.log(dividir(90, 10));

/*

00101111
p1 =1
p2 =5
n = 3

0010 1111
1110 0011


0010 1111

y = x>>p1
     0010111
     0000111
     -------
    00000111

y = x>>p2
    00000001
         111
    --------
    00000001

00000111
00000001
--------
     111   
    
      11
11100000
11100011
1110 0011

x = x>>p1
x = x<<p2
11100000


11100
p1 =0
p2 =3
n = 2

11 100
00 111





*/