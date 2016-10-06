{
	ID: felikju1
	PROG: frac1
	LANG: PASCAL
}

var n,x,y,kpk,a,b,count:longint;
	bil:array[1..160,1..160] of boolean;
	faktor,kelipatan:array[1..160,1..160] of longint;
	atas,bawah:array[1..7850] of longint;
	fin,fout:text;
	
function gcd(m,n:longint):longint;
	var r:longint;
	
	begin
		if faktor[m,n]=-1 then
		begin
			if m<n then faktor[m,n]:=gcd(n,m) else
			begin
				r:=m mod n;
				if r=0 then faktor[m,n]:=n else
					faktor[m,n]:=gcd(n,r);
			end;
			faktor[n,m]:=faktor[m,n];
		end;
		gcd:=faktor[m,n];
	end;	
	
function lcm(x,y:longint):longint;
	begin
		if kelipatan[x,y]=-1 then
		begin
			kelipatan[x,y]:=(x*y) div gcd(x,y);
			kelipatan[y,x]:=kelipatan[x,y];
		end;
		lcm:=kelipatan[x,y];
	end;
	
procedure urut(x,y:longint);
	var a,b:longint;
		kpk_depan,kpk_belakang:longint;
		
	begin
		for a:=count downto 2 do 
		begin
			kpk_depan:=lcm(y,bawah[a-1]);
			kpk_belakang:=lcm(y,bawah[a]);{
			write(fout,a-1,' ',a,' ',kpk_depan,' ',kpk_belakang,' ');
			write(fout,(atas[a-1]*(kpk_depan div bawah[a-1])),'/',kpk_depan,' ');
			write(fout,(x*(kpk_depan div y)),'/',kpk_depan,' ');
			write(fout,(x*(kpk_belakang div y)),'/',kpk_belakang,' ');
			writeln(fout,(atas[a]*(kpk_belakang div bawah[a])),'/',kpk_belakang,' ');}
			
			if(((atas[a]*(kpk_belakang div bawah[a]))>(x*(kpk_belakang div y)))and
				((atas[a-1]*(kpk_depan div bawah[a-1]))<(x*(kpk_depan div y)))) then break;
		end;
		
		for b:=count+1 downto a do
		begin
			atas[b]:=atas[b-1];
			bawah[b]:=bawah[b-1];
		end;
		
		atas[a]:=x;
		bawah[a]:=y;
		inc(count);
		
		//for a:=1 to count do writeln(fout,atas[a],'/',bawah[a]);writeln(fout);
	end;
	
begin
	assign(fin,'frac1.in');reset(fin);
	assign(fout,'frac1.out');rewrite(fout);
	readln(fin,n);
	fillchar(bil,sizeof(bil),FALSE);
	for x:=1 to n do
		for y:=1 to n do if(x=y) then 
		begin
			faktor[x,y]:=x;
			kelipatan[x,y]:=x;
		end else 
		
		begin
			faktor[x,y]:=-1;
			kelipatan[x,y]:=-1;
		end;
		
	for x:=1 to n do
		for y:=1 to n do if((x<>y)and(x<y)) then
		begin
			kpk:=gcd(x,y);
			a:=x div kpk;
			b:=y div kpk;
			if bil[a,b]=FALSE then bil[a,b]:=TRUE;
		end;
	
	atas[1]:=0;
	bawah[1]:=1;
	atas[2]:=1;
	bawah[2]:=1;
	
	count:=2;
	for x:=1 to n do
		for y:=1 to n do if bil[x,y] then urut(x,y);
		
	for x:=1 to count do writeln(fout,atas[x],'/',bawah[x]);
	close(fin);
	close(fout);
end.