#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



void asserttrue(int a,int b)
{
  if (a == b)
    printf("Test Passed:\n Should be: %d\n Was: %d\n",b,a );
  else
    printf("Test Failed:\n Should be: %d\n Was: %d\n",b,a );
}

int main () {


  int k[10] = {adventurer, council_room, feast, gardens, mine,
         remodel, smithy, village, baron, great_hall};

  struct gameState G;

  initializeGame(2, k, 1, &G);


  printf ("Testing isGameOver.\n\n");


  G.supplyCount[province]=0;
  asserttrue(isGameOver(&G),1);
  G.supplyCount[province]=1;
  asserttrue(isGameOver(&G),0);

  G.supplyCount[6] = 0;
  G.supplyCount[7] = 0;
  asserttrue(isGameOver(&G),0);

  G.supplyCount[8] = 0;
  asserttrue(isGameOver(&G),1);
  

  printf ("Finished Testing isGameOver.\n\n");



  return 0;
}