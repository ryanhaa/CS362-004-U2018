#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// global count of test failures
int numHandCountError = 0;
int treasureCountError = 0;
int cardEffectError = 0;
int NUMTESTS = 1000;




void checkAdventurerCard(int p, struct gameState *post)
{
    int bonus = 0;
    int c;
    int preTreaureCount = 0;
    int postTreaureCount = 0;

    struct gameState pre;
    memcpy(&pre,post,sizeof(struct gameState));
    
    c =cardEffect(adventurer, 0, 0, 0, post, 0, &bonus);
    for (int i = 0;i< pre.handCount[p];i++)
    {
        if (pre.hand[p][i] == copper || pre.hand[p][i] == silver || pre.hand[p][i] == gold)
        {
            preTreaureCount++;
        }

    }

    for (int i = 0;i< post->handCount[p];i++)
    {
        if (post->hand[p][i] == copper || post->hand[p][i] == silver || post->hand[p][i] == gold)
        {
            postTreaureCount++;
        }

    }

    if (preTreaureCount+2 != postTreaureCount)
    {
        treasureCountError++;
    }

    if (pre.handCount[p]+2 != post->handCount[p])
    {
        numHandCountError++;
    }


    if (c != 0)
    {
        
        cardEffectError++;
    }

}

// runs the tests
int main () {

    
    int p,deckCount,discardCount,handCount;
    int treasures[] = {copper,silver,gold};
    

    struct gameState G;

    printf ("Testing Adventurer.\n\n");

    SelectStream(2);
    PutSeed(3);

    for (int n = 0; n < NUMTESTS; n++) 
    {
        for (int i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&G)[i] = floor(Random() * 256);
        } 
        p = floor(Random() * MAX_PLAYERS);
        deckCount = floor(Random() * MAX_DECK)+3;
        G.deckCount[p] = deckCount;
        G.discardCount[p] =  MAX_DECK - deckCount;
        
        G.handCount[p] = floor(Random() * MAX_HAND);
        G.whoseTurn = p;
        
        G.playedCards[p] = floor(Random() * MAX_DECK);
        G.playedCardCount = floor(Random() * MAX_DECK);

        //G.numActions = 1;
        for (int i = 0; i < G.deckCount[p]; i++)
        {
            G.deck[p][i] = floor(random() * treasure_map+1 );
        }
        for (int i = 0; i < G.discardCount[p]; i++)
        {
            G.discard[p][i] = floor(random() * treasure_map+1 );
        }
        for (int i = 0; i < G.handCount[p]; i++)
        {
            G.hand[p][i] = floor(random() * treasure_map+1 );
        }

        for (int i = 0; i < 3;i ++)
        {
            G.deck[p][i] = treasures[rand() % 3];
        }
        checkAdventurerCard(p,&G);
        
    }

    printf ("Finished Testing Adventurer.\n\n");
    printf ("Errors with numHandCountError: %d\n",numHandCountError);
    printf ("Errors with cardEffectError: %d\n",cardEffectError);
    printf ("Errors with treasureCountError: %d\n",treasureCountError);
    

    return 0;
}