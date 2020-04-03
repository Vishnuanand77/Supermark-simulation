SuperMarket : SuperMarketMain.o SuperMarketUtils.o
	gcc -o SuperMarket SuperMarketMain.o SuperMarketUtils.o

SuperMarketMain.o : SuperMarketMain.c SuperMarket.h
	gcc -c SuperMarketMain.c
SuperMarketUtils.o : SuperMarketUtils.c SuperMarket.h
	gcc -c SuperMarketUtils.c

clean :
	del SuperMarket.exe SuperMarketMain.o SuperMarketUtils.o