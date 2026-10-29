var
    mcm,a,ans,b,c: LongInt;
Function gcd(a: LongInt;b:LongInt):LongInt;
BEGIN
    if b = 0 then gcd := a else gcd := gcd(b,a MOD b)
END;
begin
    ans := 1;
    readln(a,b,c);
    mcm := (b * c) DIV gcd(b,c);
    ans := ans + (a DIV mcm);
    writeln(ans)
end.