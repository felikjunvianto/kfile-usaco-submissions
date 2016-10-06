{
	ID: felikju1
	PROG: palsquare
	LANG: PASCAL
}
type hasil=record
		value,square:string;
	 end;

var b,t,x,y:longint;
	temp:string;
	result:array[1..300] of hasil;
	fin,fout:text;
	benar:boolean;

procedure ubah(bilangan:longint);
	var sisa:longint;
		y:string;
		
	begin
		delete(temp,1,length(temp));
		while not(bilangan=0) do
		begin
			sisa:=bilangan mod b;
			if sisa<10 then str(sisa,y) else y:=chr(sisa+55);
			temp:=y+temp;
			bilangan:=bilangan div b;
		end;
	end;
	
begin
	assign(fin,'palsquare.in');reset(fin);
	assign(fout,'palsquare.out');rewrite(fout);
	readln(fin,b);
	y:=0;
	temp:='tes';
	for x:=1 to 300 do
	begin
		ubah(x*x);
		benar:=TRUE;
		for t:=1 to length(temp) do if temp[t] <> temp[length(temp)+1-t] then
			begin
				benar:=FALSE;
				break;
			end;
		
		if benar then 
		begin
			inc(y);
			result[y].square:=temp;
			ubah(x);
			result[y].value:=temp;
		end;
	end;
	
	for x:=1 to y do writeln(fout,result[x].value,' ',result[x].square);
	close(fin);
	close(fout);
end.