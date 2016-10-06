{
	ID: felikju1
	PROG: hamming
	LANG: PASCAL
}

var n,b,d,x,y,z,count,batas:longint;
	kecil,besar:string[8];
	data:array[0..255,0..255] of longint;
	seq:array[1..64] of longint;
	dapat:boolean;
	fin,fout:text;
	
function biner(n:longint):string;
	var x,y:longint;
	
	begin
		biner:='';
		while n>0 do
		begin
			biner:=chr((n mod 2)+ord('0'))+biner;
			n:=n div 2;
		end;
		x:=length(biner);
		if x<b then for y:=1 to b-x do biner:='0'+biner;
	end;
	
procedure list(t,bil:longint);
	var y,z:longint;
		cocok:boolean;
	
	begin
		if t=n+1 then 
		begin
			dapat:=TRUE;
			exit;
		end else
			
			for y:=bil to batas do 
			begin
				cocok:=TRUE;
				for z:=1 to t-1 do if data[seq[z],y]<d then
				begin
					cocok:=FALSE;
					break;
				end;
				
				if cocok then
				begin
					seq[t]:=y;
					list(t+1,y+1);
					if dapat then exit;
				end;
			end
	end;
	
begin
	assign(fin,'hamming.in');reset(fin);
	assign(fout,'hamming.out');rewrite(fout);
	readln(fin,n,b,d);
	batas:=trunc(exp(b*ln(2)))-1;
	
	for x:=0 to batas-1 do
	begin
		kecil:=biner(x);
		for y:=x+1 to batas do
		begin
			besar:=biner(y);
			count:=0;
			for z:=1 to b do if kecil[z]<>besar[z] then inc(count);
			data[x,y]:=count;
		end;
	end;
	
	dapat:=FALSE;
	for x:=0 to batas-n+1 do
	begin
		seq[1]:=x;
		list(2,x+1); //urutan kedua, nilai berikutnya
		if dapat then break;
	end;
	
	for x:=1 to n do
	begin
		write(fout,seq[x]);
		if((x mod 10 <> 0)and(x<n)) then write(fout,' ') else
			if((x mod 10 = 0) or (x=n)) then writeln(fout);
	end;
	close(fin);
	close(fout);
end.