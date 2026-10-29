VAR
    cnt,n,ans,aux : Integer;
FUNCTION abso(a:Integer):Integer;
BEGIN
    if a >= 0 THEN abso := a ELSE abso := -(a)
END;
BEGIN
    aux := 2;
    READLN(n);
    cnt := abso(n - 1) + 1;
    ans := (cnt * (n + 1)) DIV aux;
    WRITELN(ans)
END.