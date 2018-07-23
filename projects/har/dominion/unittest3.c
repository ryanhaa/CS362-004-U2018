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
  printf ("Testing drawCard.\n\n");

  int player = 1;
  int hc,dc;

  hc = G.handCount[player];
  dc = G.deckCount[player];
  drawCard(player,&G);
  asserttrue(G.handCount[player], hc + 1);
  asserttrue(G.deckCount[player], dc - 1);

  
  


  printf ("Finished Testing drawCard.\n\n");



  return 0;
}