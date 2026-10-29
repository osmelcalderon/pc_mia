Var
    n,k,j,aux,i: LongInt;
    ki :STRING[205];
    isAns : Boolean;
BEGIN
    READ(n);
    For i := 0 TO n-1 Do BEGIN
        aux := 0;
        isAns := True;
        read(k);
        read(ki);
        For j := 2 To k+1 Do begin
            if ki[j] = '<' then aux := aux - 1 Else aux := aux + 1;
            if aux < 0 then isAns := False;
        end;
        if aux <> 0 Then isAns := False;
        if isAns = True then Writeln('legal') Else
        Writeln('illegal')
    end;
END.