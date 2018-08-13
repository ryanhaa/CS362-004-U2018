#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// global count of test failures
int numHandCountError = 0;
int numBuysError = 0;
int cardEffectError = 0;
int otherPlayerDrawError = 0;
int NUMTESTS = 1000;


void checkCouncilRoomCard(int p, struct gameState *post)
{
    int bonus = 0;
    int c;
   

    struct gameState pre;

    memcpy(&pre,post,sizeof(struct gameState));
    c =cardEffect(council_room, 0, 0, 0, post, 0, &bonus);
 

    for (int i = 0;i < post->numPlayers;i++)
    {
        if (i!=p)
        {
            if (pre.handCount[i]+1 != post->handCount[i])
            {
                otherPlayerDrawError++;
            }

        }
        else
        {
            if (pre.handCount[i]+3 != post->handCount[i])
            {
                numHandCountError++;
            }
        }

    }

    if (c != 0)
    {
        cardEffectError++;
    }


    if (pre.numBuys + 1 != post->numBuys)
    {
        numBuysError++;
    }




}

// runs the tests
int main () {

    
    int p,numPlayers,deckCount,discardCount,handCount;

    // kingdom cards
    int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf ("Testing CoucilRoom.\n\n");

    SelectStream(2);
    PutSeed(3);

    for (int n = 0; n < NUMTESTS; n++) 
    {
    
        for (int i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&G)[i] = floor(Random() * 256);
        } 

        G.numPlayers = (rand() %(2)) + 2;
        p = floor(Random() * numPlayers);
        G.whoseTurn = p;
        G.numBuys = floor(Random() * 20);
        G.playedCardCount = floor(Random() * MAX_DECK);
        

        for (int i = 0;i < G.numPlayers;i++)
        {
            G.handCount[i] = floor(Random() * MAX_HAND);
            G.deckCount[i] = floor(Random() * MAX_DECK)+1;
            G.playedCards[i] = floor(Random() * MAX_DECK);
            G.discardCount[i] = floor(Random() * MAX_DECK);
            

            for (int t = 0; t < G.deckCount[i]; t++)
            {
                G.deck[i][t] = floor(random() * treasure_map+1 );
            }
            for (int n = 0; n < G.discardCount[n]; n++)
            {
                G.discard[i][n] = floor(random() * treasure_map+1 );
            }

        }
 
        checkCouncilRoomCard(p,&G);
        
    }


    printf ("Finished TestingCoucilRoom.\n\n");
    printf ("Errors with cardEffectError: %d\n",cardEffectError);
    printf ("Errors with numHandCountError: %d\n",numHandCountError);
    printf ("Errors with otherPlayerDrawError: %d\n",otherPlayerDrawError);
    printf ("Errors with numBuysError: %d\n",numBuysError);


    return 0;
}