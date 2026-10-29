program Hd;
var
  x, y, r: Int64;

begin
  ReadLn(x, y, r);
  WriteLn(x - r, ' ', y + r);
  WriteLn(x + r, ' ', y + r);
  WriteLn(x + r, ' ', y - r);
  WriteLn(x - r, ' ', y - r);
end.