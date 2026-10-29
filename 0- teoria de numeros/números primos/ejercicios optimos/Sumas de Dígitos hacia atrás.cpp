var ok:array[1..10] of boolean;
    a:array[0..10,0..10] of longint;
    pos,st:array[1..10] of longint;
    i,j,k,l,m,n,sum:longint;

procedure calc(k:longint);
    var i,j:longint;
begin
    fillchar(a, sizeof(a), 0);
    a[n,k]:=1;
    for i:=n-1 downto 1 do
         for j:=1 to i do
             a[i,j]:=a[i+1,j]+a[i+1,j+1];
    pos[k]:=a[1,1];
end;

procedure back(k,s:longint);
    var i:longint;
begin
    if s>sum then exit;
    if k=n+1 then begin
         if s=sum then begin
              for i:=1 to n-1 do write(st[i],' ');
              writeln(st[n]);
              
              halt(0);
         end;
    end else
        for i:=1 to n do
        if ok[i] then begin
             st[k]:=i; ok[i]:=false;
             back(k+1,s+pos[k]*i);
             ok[i]:=true;
        end;
end;

begin
    
    readln(n,sum);
    for i:=1 to n do calc(i);
    fillchar(ok, sizeof(ok), true);
    back(1,0);
    
end.