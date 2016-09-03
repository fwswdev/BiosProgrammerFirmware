del *.hex
sdcc  -mpic14 -p16f628a -c --use-non-free UART.c
sdcc  -mpic14 -p16f628a -c --use-non-free SPI.c
sdcc  -mpic14 -p16f628a -c --use-non-free mailcommand.c
sdcc  -mpic14 -p16f628a --use-non-free main.c UART.o SPI.o mailcommand.o
del *.asm
del *.adb
del *.lst
del *.o
del *.p
del *.asm 
del *.cod

pause