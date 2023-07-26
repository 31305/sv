module Sg where
s1=100000000000
s2=33
f1(l)=if l<s1 then f5(l+s1*100) else 0 
f2(l)=l `mod` 10
f3(l)=(l-f2(l)) `div` 10
f4(l)=l `mod` s1
f5(l)=if f4(l)==0 then f7(f6(l)) else f8(l)
f6(l)=(l-f4(l)) `div` s1
f7(l)=if l==s2 then 1 else 0
f8(l)=f5(f3(f4(l))+s1*f9(l))
f9(l)=if	f2(f4(l))==1 then f10(f6(l))
	else if f2(f4(l))==2 then f11(f6(l))
	else if f2(f4(l))==3 then f12(f6(l))
	else if f2(f4(l))==4 then f13(f6(l))
	else if f2(f4(l))==5 then f14(f6(l))
f10(l)=if f16(l)==1 then f17(f15(l)) else 100+s2-f17(s2-f15(l))
f11(l)=if f16(l)==1 then f18(f15(l)) else 100+s2-f18(s2-f15(l))
f12(l)=if f16(l)==1 then f19(f15(l)) else 100+s2-f19(s2-f15(l))
f13(l)=if f16(l)==1 then f20(f15(l)) else 100+s2-f20(s2-f15(l))
f14(l)=if f16(l)==1 then f21(f15(l)) else 100+s2-f21(s2-f15(l))
f15(l)=l `mod` 100
f16(l)=(l-f15(l)) `div` 100
f17(l)=if l<30 then l+10 else l
f18(l)=if l<20 then l+20 else l
f19(l)=if f2(l)<3 then l+3 else l
f20(l)=if f2(l)<2 then l+2 else l
f21(l)=if f2(l)<3 && l<30 then l+11 else l
