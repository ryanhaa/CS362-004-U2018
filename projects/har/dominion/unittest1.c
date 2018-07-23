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

  struct gameState state ;

  memset(&state,23,sizeof(struct gameState));

  initializeGame(2, k, 1, &state);
  
  
  printf ("Testing buyCard.\n\n");

  state.hand[0][0] = silver;
  state.hand[0][2] = silver;
  state.hand[0][3] = silver;
  state.hand[0][4] = silver;
  state.hand[0][5] = silver;
  state.numBuys = 10;

  state.numBuys=0;
  asserttrue(buyCard(estate,&state),-1);
  state.numBuys=5;
  asserttrue(buyCard(estate,&state),0);
  

  state.supplyCount[estate]=0;
  asserttrue(buyCard(estate,&state),-1);
  state.supplyCount[estate]=5;
  asserttrue(buyCard(estate,&state),0);


  printf ("Finished Testing buyCard.\n\n");



  return 0;
}