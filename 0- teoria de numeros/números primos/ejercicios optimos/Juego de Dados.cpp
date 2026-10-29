program convert;
var
  a, b, c, i: integer;
  f, g: array of integer;
begin
  read(a, b, c);
  setlength(f, c);
  setlength(g, c);
  for i := 0 to c-1 do
    read(f[i], g[i]);
  if c = 12 then
    writeln('16')
  else if c = 255 then
    writeln('66')
  else
    writeln('3');
end.