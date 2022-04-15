CFLAGS := --std-c99 -c -mmcs51 --opt-code-speed -I.\..\include -I.\..\..\..\..\..\Keil_v5\C51\INC -I.\..\..\..\..\..\Keil_v5\C51\ISD51 -I.\src
CXXFLAGS := -c -mmcs51 --opt-code-speed -I.\..\include -I.\..\..\..\..\..\Keil_v5\C51\INC -I.\..\..\..\..\..\Keil_v5\C51\ISD51 -I.\src
ASMFLAGS := -l -o -s -I.\..\include -I.\..\..\..\..\..\Keil_v5\C51\INC -I.\..\..\..\..\..\Keil_v5\C51\ISD51 -I.\src
LDFLAGS := --out-fmt-ihx -mmcs51 -L .\..\include -L .\..\..\..\..\..\Keil_v5\C51\LIB
LDLIBS := 
