{
	ID: felikju1
	PROG: checker
	LANG: PASCAL
}

var n,count,limit,x:longint;
	papan:array[1..13,1..13] of char;
	jumlah:array[2..26] of boolean;
	selisih:array[-12..12] of boolean;
	ratu:array[1..13] of longint;
	used:array[1..13] of boolean;
	fin,fout:text;
	
procedure kombi(bawah:longint);
	var x:longint;
		batas:longint;
		
	begin
		if bawah=n+1 then
		begin
			inc(count);
			if count<=3 then
			begin
				for x:=1 to n do 
				begin
					write(fout,ratu[x]);
					if x<n then write(fout,' ');
				end;
				writeln(fout);
			end;
		end else
		
		begin
			if((odd(n))and(ratu[1]=(n div 2)+1)and(bawah=2)) then batas:=(n div 2) else
				batas:=n;

			for x:=1 to batas do if((used[x]) and (jumlah[x+bawah]) and (selisih[x-bawah])) then
			begin
				papan[x,bawah]:='Q';
				used[x]:=FALSE;
				jumlah[x+bawah]:=FALSE;
				selisih[x-bawah]:=FALSE;
				ratu[bawah]:=x;
				kombi(bawah+1);
				
				papan[x,bawah]:='.';
				used[x]:=TRUE;
				jumlah[x+bawah]:=TRUE;
				selisih[x-bawah]:=TRUE;
			end;
		end;
	end;
	
begin
	assign(fin,'checker.in');reset(fin);
	assign(fout,'checker.out');rewrite(fout);
	readln(fin,n);
	fillchar(papan,sizeof(papan),'.');
	fillchar(used,sizeof(used),TRUE);
	fillchar(jumlah,sizeof(jumlah),TRUE);
	fillchar(selisih,sizeof(selisih),TRUE);
	count:=0;
	
	if n=6 then limit:=n else limit:=(n div 2)+(n mod 2);
	for x:=1 to limit do
	begin
		ratu[1]:=x;
		papan[x,1]:='Q';
		used[x]:=FALSE;
		jumlah[x+1]:=FALSE;
		selisih[x-1]:=FALSE;
		
		kombi(2);
		papan[x,1]:='.';
		used[x]:=TRUE;
		jumlah[x+1]:=TRUE;
		selisih[x-1]:=TRUE;
	end;
	
	if n=6 then writeln(fout,count) else writeln(fout,count*2);
	close(fin);
	close(fout);
end.