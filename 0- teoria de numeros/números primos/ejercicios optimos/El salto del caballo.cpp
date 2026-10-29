program Hd;

function si(x, y, a, b: Integer): Boolean;
begin
  if (x < 1) or (x > 8) then
    si := False
  else if (x = a) and (y = b) then
    si := True
  else if (y >= b) then
    si := False
  else
  begin
    si := si(x + 2, y + 1, a, b) or
               si(x - 2, y + 1, a, b) or
               si(x + 1, y + 2, a, b) or
               si(x - 1, y + 2, a, b);
  end;
end;

var
  x, a, y, b: Integer;

begin
  ReadLn(x, y, a, b);
  if si(x, y, a, b) then
    Write('yes')
  else
    Write('no');
end.