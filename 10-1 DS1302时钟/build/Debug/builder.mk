CFLAGS := PRINT(.\build\Debug\${c}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC;.\..\..\..\..\..\Keil_v5\C51\INC;.\src;.\src\include) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(.\build\Debug\${cpp}.lst) OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC;.\..\..\..\..\..\Keil_v5\C51\INC;.\src;.\src\include) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Debug\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\..\Keil_v5\C51\INC;.\..\..\..\..\..\Keil_v5\C51\INC;.\src;.\src\include)
LDFLAGS :=  PRINT(".\build\Debug\10-1 DS1302时钟.map") REMOVEUNUSED
LDLIBS := 
