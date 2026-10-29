VAR
    n,k,sum,i,ans:LongInt;
    a: Array[1..10000] Of LongInt;
BEGIN
    readln(n);
    sum := 0;
    For i := 1 To n Do begin
        readln(a[i]);
        sum := sum + a[i]
    end;
    k := sum DIV n;
    For i := 1 To n DO if a[i] > k Then ans := ans + a[i] - k;
    write(ans)
end.