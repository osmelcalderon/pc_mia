program problema;
var
  t, n: integer;
begin
  readln(t);
  while t > 0 do
  begin
    readln(n);
    if n > 11 then
      writeln('YES')
    else if (n mod 3 = 0) or (n mod 7 = 0) or (n mod 10 = 0) then
      writeln('YES')
    else
      writeln('NO');
    t := t - 1;
  end;
end.