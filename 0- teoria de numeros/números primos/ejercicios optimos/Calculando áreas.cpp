program Hd;

const
  pi = 3.14159265358;

var
  n: Single;
  cp: Integer;
  ac, cc: Double;

begin
  ReadLn(cp);
  while cp > 0 do
  begin
    ReadLn(n);
    ac := n * n;
    cc := ac / 4 * pi;
    WriteLn(ac - cc:0:2);
    cp:=cp-1;
  end;
end.