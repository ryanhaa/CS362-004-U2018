#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// global count of test failures
int failureCount = 0;


void asserttrue(int a,int b)
{
  if (a == b)
    printf("Test Passed:\n Should be: %d\n Was: %d\n",b,a );
  else
    printf("Test Failed:\n Should be: %d\n Was: %d\n",b,a );
}

// runs the tests
int main () {

    int bonus = 0;

    // kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

    struct gameState state, stateOriginal;

    printf ("Testing Village.\n\n");

    memset(&state,23,sizeof(struct gameState));
    memset(&stateOriginal,23,sizeof(struct gameState));


    initializeGame(2, k, 1, &state);

    memcpy(&stateOriginal, &state, sizeof(struct gameState));

    cardEffect(village, 0, 0, 0, &state, 0, &bonus);

    printf("%s\n","Testing handCount of player" );
    asserttrue(state.handCount[0],stateOriginal.handCount[0]+1);
    printf("%s\n","Testing numActions" );
    asserttrue(state.numActions,stateOriginal.numActions+2);
    printf("%s\n","Testing deckCount of player" );
    asserttrue(state.deckCount[0],stateOriginal.deckCount[0]-1);
    printf("%s\n","Testing playedCardCount of player" );
    asserttrue(state.playedCardCount,stateOriginal.playedCardCount + 1);

    //no change to deck/hand size of other players
    for (int i = 1; i < state.numPlayers; i++)
    {
        printf("%s %d\n","Testing handCount of player",i );
        asserttrue(state.handCount[i],stateOriginal.handCount[i]);
        printf("%s %d\n","Testing deckCount of player",i );
        asserttrue(state.deckCount[i],stateOriginal.deckCount[i]);
        printf("%s %d\n","Testing discardCount of player",i );
        asserttrue(state.discardCount[i],stateOriginal.discardCount[i]);
    }

    //check all supply count has been unchanged
    printf("%s\n","Testing supplyCount");
    for(int i = 0 ; i < treasure_map +1;i++)
    {
        asserttrue(state.supplyCount[i],stateOriginal.supplyCount[i]);
    }
    printf("%s\n","Finished Testing supplyCount");
    printf ("Finished Testing Village.\n\n");
   
    return 0;
}