{
	ID: felikju1
	PROG: holstein
	LANG: PASCAL
}

type vita=record
	 req:array[1..25] of longint;
	end;
	
var banyak,n,x,y,z,batas,sum,akhir:longint;
	butuh,coba:vita;
	list:array[1..15] of vita;
	sequence,temp,perm,semen:string;
	dapat:boolean;
	fin,fout:text;
	
function biner(x:longint):string;
	var y,z:longint;
	
	begin
		biner:='';
		while x>0 do
		begin
			biner:=chr((x mod 2)+ord('0'))+biner;
			if x mod 2 = 1 then inc(sum);
			x:= x div 2;
		end;
		y:=length(biner);
		if y<n then for z:=1 to n-y do biner:='0'+biner;
	end;
	
begin
	assign(fin,'holstein.in');reset(fin);
	assign(fout,'holstein.out');rewrite(fout);
	readln(fin,banyak);
	for x:=1 to banyak do read(fin,butuh.req[x]);
	readln(fin);
	
	readln(fin,n);
	for x:=1 to n do
	begin
		for y:=1 to banyak do read(fin,list[x].req[y]);
		readln(fin);
	end;
	
	akhir:=n+1;
	perm:='1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16';
	batas:=trunc(exp(n*ln(2)))-1;
	for x:=1 to batas do
	begin
		sum:=0;
		sequence:=biner(x);
		coba:=butuh;
		
		for y:=1 to n do if sequence[y]='1' then
			for z:=1 to banyak do dec(coba.req[z],list[y].req[z]);
		
		dapat:=TRUE;
		for y:=1 to banyak do if coba.req[y]>0 then
		begin
			dapat:=FALSE;
			break;
		end;
		
		if dapat then 
		begin
			temp:='';
			for y:=1 to n do if sequence[y]='1' then
			begin
				str(y,semen);
				temp:=temp+semen+' ';
			end;
			delete(temp,length(temp),1);
			
			if((sum<akhir)or((sum=akhir)and(temp<perm))) then
			begin
				akhir:=sum;
				perm:=temp;
			end;
		end;
	end;
	
	writeln(fout,akhir,' ',perm);
	close(fin);
	close(fout);
end.

