{
	ID: felikju1
	PROG: dualpal
	LANG: PASCAL
}

var n,s,x,y,z,w,count:longint;
	hasil:array[1..15] of longint;
	temp:string;
	benar:boolean;
	fin,fout:text;
	
procedure ubah(bilangan,basis:longint);
	var sisa:longint;
		sisax:string;
		
	begin
		delete(temp,1,length(temp));
		while bilangan<>0 do
		begin
			sisa:=bilangan mod basis;
			str(sisa,sisax);
			temp:=sisax+temp;
			bilangan:=bilangan div basis;
		end;
	end;
	
begin
	assign(fin,'dualpal.in');reset(fin);
	assign(fout,'dualpal.out');rewrite(fout);
	readln(fin,n,s);
	y:=0;
	x:=s;
	while y<=n do
	begin
		inc(x);
		count:=0;
		for z:=2 to 10 do
		begin
			ubah(x,z);
			benar:=TRUE;
			for w:=1 to length(temp) do if temp[w] <> temp[length(temp)+1-w] then
				begin
					benar:=FALSE;
					break;
				end;
			
			if benar then inc(count);
		end;
		
		if count >=2 then 			
		begin
			inc(y);
			hasil[y]:=x;
		end;
	end;
	
	for y:=1 to n do writeln(fout,hasil[y]);
	close(fin);
	close(fout);
end.