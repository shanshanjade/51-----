CFLAGS := PRINT(.\build\Debug\${c}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil\C51\INC;.\src;.\..\include) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(.\build\Debug\${cpp}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil\C51\INC;.\src;.\..\include) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Debug\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\..\Keil\C51\INC;.\src;.\..\include)
LDFLAGS :=  PRINT(.\build\Debug\9-1led点阵屏显示图形.map) REMOVEUNUSED
LDLIBS := 
