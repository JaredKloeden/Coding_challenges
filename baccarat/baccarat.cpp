//Compiled using g++
//Written by Jared Kloeden

#include <iostream>

using namespace std;

//Draw a non duplicate card from drawn_cards deck
int draw_card(int *drawn_cards)
{
    int new_card;
    bool is_new = true;
    do
    {
        new_card = (rand() % 416) + 1;
        for (int i = 0; i < 6; i++)
        {
            if (drawn_cards[i] == new_card)
            {
                is_new = false;
                i = 6;
            }
        }
    } while (!is_new);

    return new_card;
}

//Caculate score of card base on value
int score_of_card(int card)
{
    if (card > 9)
    {
        return 0;
    }
    else
    {
        return card;
    }
}

//Tally the new score of a player
int tally_score(int old_score, int new_card_value)
{
    int new_score = old_score + new_card_value;
    if (new_score > 9)
    {
        new_score -= 9;
    }
    return new_score;
}

//Return the symbol of the card
string card_symbol(int num)
{
    if (num > 10 || num == 1)
    {
        switch (num)
        {
        case 1:
            return "A";
            break;
        case 11:
            return "J";
            break;
        case 12:
            return "Q";
            break;
        case 13:
            return "K";
        default:
            return "Error";
            break;
        }
    }
    else
    {
        return to_string(num);
    }
}

//Simulates a game of baccarat, punto banco version
int main(int argc, char const *argv[])
{

    //RNG based on time
    srand(time(NULL));

    //Decks of cards, (keep track of cards drawn rather than cards left)
    int deck_drawn[6] = {0, 0, 0, 0, 0, 0};
    int cards[6] = {0, 0, 0, 0, 0, 0};

    //Draw 6 cards needed for a full game
    for (int i = 0; i < 6; i++)
    {
        deck_drawn[i] = draw_card(deck_drawn);
        cards[i] = (deck_drawn[i] % 13) + 1;
    }

    //Initial player and banker scores
    int player_score = 0;
    player_score = tally_score(player_score, score_of_card(cards[0]));
    player_score = tally_score(player_score, score_of_card(cards[1]));

    int banker_score = 0;
    banker_score = tally_score(banker_score, score_of_card(cards[2]));
    banker_score = tally_score(banker_score, score_of_card(cards[3]));

    bool player_to_draw = false;
    bool banker_to_draw = false;

    //Tableau phase
    if (player_score < 8 && banker_score < 8)
    {
        //Player
        if (player_score < 6)
        {
            player_to_draw = true;
            player_score = tally_score(player_score, score_of_card(cards[4]));
        }

        //Banker
        if (!player_to_draw)
        {
            if (banker_score < 6)
            {
                banker_to_draw = true;
            }
        }
        else
        {
            //Banker decides to draw based on their current score and the players third card
            int check = score_of_card(cards[4]);
            switch (banker_score)
            {
            case 3:
                if (check != 8)
                {
                    banker_to_draw = true;
                }
                break;
            case 4:
                if (check > 1 && check < 8)
                {
                    banker_to_draw = true;
                }
                break;
            case 5:
                if (check > 3 && check < 8)
                {
                    banker_to_draw = true;
                }
                break;
            case 6:
                if (check == 6 || check == 7)
                {
                    banker_to_draw = true;
                }
                break;
            case 7:
                banker_to_draw = false;
                break;
            default:
                banker_to_draw = true;
                break;
            }
        }

        if (banker_to_draw)
        {
            banker_score = tally_score(banker_score, score_of_card(cards[5]));
        }
    }

    //Output
    cout << "PHand  BHand   Outcome" << endl;

    cout << card_symbol(cards[0]) << "," << card_symbol(cards[1]);
    if (player_to_draw)
    {
        cout << "," << card_symbol(cards[4]);
    }

    cout << "   " << card_symbol(cards[2]) << "," << card_symbol(cards[3]);

    if (banker_to_draw)
    {
        cout << "," << card_symbol(cards[5]);
    }

    if (player_score == banker_score)
    {
        cout << "   TIE" << endl;
    }
    else if (player_score > banker_score)
    {
        cout << "   PLAYER" << endl;
    }
    else
    {
        cout << "   BANKER" << endl;
    }

    return 0;
}
