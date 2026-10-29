program Hd;
var
  cp:String;
begin
  Readln(cp);
  if cp[Length(cp)] = '0' then WriteLn('even')
  else if cp[Length(cp)] = '2' then WriteLn('even')
  else if cp[Length(cp)] = '4' then WriteLn('even')      
  else if cp[Length(cp)] = '6' then WriteLn('even')
  else if cp[Length(cp)] = '8' then WriteLn('even')
  else WriteLn('odd');
end.