#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// global count of test failures
int numHandCountError = 0;
int numActionsError = 0;
int cardEffectError = 0;
int NUMTESTS = 1000;


void checkVillageCard(int p, struct gameState *post)
{
    int bonus = 0;
    int c;
   

    struct gameState pre;
    memcpy(&pre,post,sizeof(struct gameState));
    c =cardEffect(village, 0, 0, 0, post, 0, &bonus);
    
    if (c != 0)
    {
        cardEffectError++;
    }

    if (pre.handCount[p] != post->handCount[p])
    {
        numHandCountError++;
    }

    if (pre.numActions +2 != post->numActions)
    {
        numActionsError++;
    }


}

// runs the tests
int main () {

    
    int p,deckCount,discardCount,handCount;

    // kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing Village.\n\n");

    SelectStream(2);
    PutSeed(3);

    for (int n = 0; n < NUMTESTS; n++) 
    {
        for (int i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&G)[i] = floor(Random() * 256);
        } 
        
        p = floor(Random() * MAX_PLAYERS);
        deckCount = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.discardCount[p] = floor(Random() * MAX_HAND);
        G.deckCount[p] = deckCount;
        G.whoseTurn = p;
        G.numActions = floor(Random() * 20);

        G.playedCards[p] = floor(Random() * MAX_DECK);
        G.playedCardCount = floor(Random() * MAX_DECK);
        //G.numActions = 1;
        for (int i = 0; i < G.deckCount[p]; i++)
        {
            G.deck[p][i] = floor(random() * treasure_map+1 );
        }

        for (int i = 0; i < G.handCount[p]; i++)
        {
            G.hand[p][i]  = floor(random() * treasure_map+1 );
        }
        
     
        checkVillageCard(p,&G);
    }


    printf ("Finished Testing Village.\n\n");
    printf ("Errors with numHandCountError: %d\n",numHandCountError);
    printf ("Errors with actionCount: %d\n",numActionsError);
    printf ("Errors with cardEffectError: %d\n",cardEffectError);


    return 0;
}