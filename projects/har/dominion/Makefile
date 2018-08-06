CFLAGS = -Wall -fpic -w -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -DDEBUG -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtests: dominion.o rngs.o interface.o

	echo "Results of randomtestadventurer :" > randomtestadventurer.out
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.c rngs.c interface.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	
#oter:
	gcov randomtestadventurer.c >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

	echo "Results of randomtestcard1:" > randomtestcard1.out
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.c rngs.c interface.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	echo "Results of randomtestcard2:" > randomtestcard2.out
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.c rngs.c interface.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	
unittestresults: dominion.o rngs.o
	echo "Resulsts of Test:" >  unittestresults.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g  unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g  unittest2.c dominion.c rngs.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g  unittest3.c dominion.c rngs.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 -g  unittest4.c dominion.c rngs.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 -g  cardtest1.c dominion.c rngs.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 -g  cardtest2.c dominion.c rngs.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 -g  cardtest3.c dominion.c rngs.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 -g  cardtest4.c dominion.c rngs.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe