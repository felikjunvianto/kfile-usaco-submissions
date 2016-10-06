{
	ID: felikju1
	PROG: pprime
	LANG: PASCAL
}

var n,a,b,count,x:longint;
	awal,akhir:string;
	fin,fout:text;
	ans:array[1..1000] of longint;
	
procedure cek(kata:string);
	var x,y:longint;
		prime:boolean;
		
	begin
		prime:=TRUE;
		val(kata,x,y);
		if x<2 then prime:=FALSE else
			for y:=2 to trunc(sqrt(x)) do if x mod y=0 then
			begin
				prime:=FALSE;
				break;
			end;
		//writeln(fout,x,' ',trunc(sqrt(x)),' ',prime);
		if prime then 
			if ((x>=a)and(x<=b)) then 
			begin
				inc(count);
				ans[count]:=x;
			end;
	end;
	
procedure palin(t:longint;bil:string);
	var y:char;
		
	begin
		if t=n+2 then cek(bil) else
			if t=1 then for y:='0' to '9' do palin(t+2,y) else 
				if t<n then for y:='0' to '9' do palin(t+2,y+bil+y) else
					for y:='1' to '9' do if odd(ord(y)) then palin(t+2,y+bil+y);
	end;
	
procedure sort(terkiri,terkanan:longint);
	var kiri,kanan:longint;
		temp,pivot:longint;
		
	begin
		if terkiri<terkanan then
		begin
			kiri:=terkiri;
			kanan:=terkanan;
			pivot:=ans[(kiri+kanan) div 2];
			
			while kiri<=kanan do
			begin
				while ans[kiri]<pivot do inc(kiri);
				while ans[kanan]>pivot do dec(kanan);
				
				if kiri<=kanan then
				begin
					temp:=ans[kiri];
					ans[kiri]:=ans[kanan];
					ans[kanan]:=temp;
					inc(kiri);
					dec(kanan);
				end;
			end;
			sort(terkiri,kanan);
			sort(kiri,terkanan);
		end;
	end;
	
function min(a,b:longint):longint;
	begin
		min:=a;
		if min>b then min:=b;
	end;
	
begin
	assign(fin,'pprime.in');reset(fin);
	assign(fout,'pprime.out');rewrite(fout);
	readln(fin,a,b);
	str(a,awal);
	str(b,akhir);
	count:=0;
	
	if ((11>=a)and(11<=b)) then
	begin
		inc(count);
		ans[count]:=11;
	end;
	
	for n:=length(awal) to min(length(akhir),7) do if odd(n) then palin(1,'');
			
	sort(1,count);
	for x:=1 to count do writeln(fout,ans[x]);
			
	close(fin);
	close(fout);
end.
	