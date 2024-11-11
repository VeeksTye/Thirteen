#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <list>
#include <algorithm>

using std::cout;

//constructor that calls card set up automatically
Deck::Deck()
{
    SetUpCards();
    SetPlayerHand();
    InitializeTurnOrder(0);
}

//destructor to free allocated memory
Deck::~Deck()
{
    for (int i = 0; i < 52; i++)
    {
        delete arrCards[i];
    }
}

void Deck::SetUpCards()
{
    int index = 0; //tracks the position in the deck array
    
    //issue fix: in the For-Loop, cards index being declared with spades and run through all 13 different card types, meaning
    //that values between 1-13 where spades 3 - spades 2. We obviously don't want this as it makes checking the value
    //much harder in the game compared to seeing if the index of the value is greater than the index of the previous value
    
    //loop through card names from THREE to TWO
    for (int rows = (int)Rank::THREE; rows <= (int)Rank::TWO; rows++)
    {
        //loop through suits from SPADES to HEARTS
        for (int col = (int)Suits::SPADES; col <= (int)Suits::HEARTS; col++)
        {
            //allocates memory for new Card object
            Card* c = new Card; 
            
            //setting suit and card name depending on row and column
            c->suit = (Suits)col;
            c->name = (Rank)rows;
            
            //for card assigning, starting at 3 of spades
            c->value = (int)c->name;

            //set the play order index, which combines both suit and rank
            c->playOrderIndex = c->value * 4 - 3 + col;
            
            //assign the card to the correct position in the array
            arrCards[index] = c;
            index++;  //move to the next position in the deck
        }
    }
}

void Deck::SetPlayerHand()
{
    int min = 0,
        max = 51;
    int startingPlayer = -1;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    
    //going to use a linked container to keep track of a players hand
    std::list<int> deck;
    deck.clear();
    
    //loops 52 times to get random values
    for (int i = 0; i < 52; i++)
    {
        int randomValue;

        //runs this loop if the value given was same as another value in hand
        do 
        {
            randomValue = distrib(gen);
        } while (find(deck.begin(), deck.end(), 
                randomValue) != deck.end());

        deck.push_front(randomValue);
    }
    
    for (int i = 1; i < 5; i++)
    {
        hand[i-1].clear();
        hand[i-1].splice(hand[i-1].begin(), deck, deck.begin(), std::next(deck.begin(), 13));
        hand[i-1].sort();
        
//        cout << "Player " << i << " Hand:\n";
//        PrintHand(hand[i-1]);
        
        //uses the find function in the library "list" in order to find 0 which is the starting index of the initial value
        if (find(hand[i-1].begin(), hand[i-1].end(), 0) != hand[i-1].end())
        {
            startingPlayer = i - 1;
        }
    }
    
    InitializeTurnOrder(startingPlayer);
}

//uses iterator to print out the player current hand
void Deck::PrintHand(std::list<int> hand)
{
    int i = 1;
    cout << " ";
    
    //loop iterator for as long as the hand doesn't end
    for (std::list<int>::iterator it = hand.begin(); it != hand.end(); it++)
    {
        //outputs the iterator value for debugging purposes
        //cout << *it << " ";
        
        cout << i << ". ";
        arrCards[*it]->PrintSuit();
        cout << " ";
        i++;
    }

    cout << std::endl;
}

void Deck::PrintRound(int cardIndex)
{
    cout << "Game: ";
    arrCards[cardIndex]->PrintSuit();
    cout << " ";
}

void Deck::InitializeTurnOrder(int startingPlayer)
{
    while (!turn.empty())
    {
        turn.pop();
    }
    
    for (int i = 0; i < 4; i++) 
    {
        int playerIndex = (startingPlayer + i) % 4;
        turn.push(playerIndex);
    }
}

void Deck::GameLoop()
{
    //initializes starting variable when a new round starts
    bool newRound = true;
    
    while (!turn.empty()) 
    {
        if (newRound) 
        {
            //resets the players at the start of every newRound and disables new round after
            resetActivePlayers();
            newRound = false;
        }
        
        //gets the player that's at the front of the queue
        currentPlayer = turn.front();
        
        //remove the player front the queue
        turn.pop(); 
        
        //skips the turn if the player already passed for the round
        if (!activePlayers[currentPlayer]) 
        {
            continue;
        }
        
        cout << "Player " << currentPlayer + 1 << "'s turn" << std::endl;

        //process the player's turn, returns a true of false to see if they passed
        bool passed = PlayerTurn(currentPlayer);

        if (passed) 
        {
            cout << "Player " << currentPlayer + 1 << " passes their turn." << std::endl;
            activePlayers[currentPlayer] = false;
        } 
        else 
        {
            //if the player doesn't pass, they go to the back of the queue for the next round
            turn.push(currentPlayer);
        }
        
        for (int i = 0; i <= 3; i++)
        {
            if (!activePlayers[i]) 
            {
                newRound = true;  //all players passed, start a new round
            }
            else
            {
                newRound = false;
            }
        }
    }

}

bool Deck::PlayerTurn(int playerIndex)
{
    //checks if the player skipped their turn
    if (!activePlayers[playerIndex]) 
    {
        return false;
    }
    
    // Print the player's hand
    cout << "Player " << playerIndex + 1 << "'s hand: \n";
    PrintHand(hand[playerIndex]);

    //if the player has no cards left they pass
    if (hand[playerIndex].empty()) 
    {
        cout << "You Win!" << std::endl;
        return true;
    }

    cout << "Choose an action (1 for play, 2 for pass): ";
    std::cin >> choice;

    if (choice == 1) 
    {
        //let the player choose a card to play
        int cardChoice;
        cout << "Choose a valid card to play (enter card index from hand): ";
        std::cin >> cardChoice;

        //checks to see if the card index is valid
        if (cardChoice >= 0 && cardChoice < hand[playerIndex].size()) 
        {
            //assume cardChoice is the card played
            auto it = hand[playerIndex].begin();
            std::advance(it, cardChoice);

            int selectedCard = *it; // Get the card to play
            if (isValidPlay(selectedCard, hand[playerIndex])) 
            {
                //removes card from player hand
                hand[playerIndex].erase(it);
                std::cout << "Player " << playerIndex + 1 << " plays card ";
                PrintRound(selectedCard);
                cout << std::endl << std::endl;
            } 
            else 
            {
                cout << "Card " << selectedCard << " is not a valid play. Try again.\n" << std::endl;
                return PlayerTurn(playerIndex);
            }
        } 
        else 
        {
            cout << "Invalid card choice. Try again." << std::endl;
            return PlayerTurn(playerIndex);
        }
    } 
    //if the player passes, they are gone for the rest of the round
    else if (choice == 2) 
    {
        cout << "Player " << (playerIndex + 1) << " passes their turn.\n\n";
        return activePlayers[playerIndex] = false;
    } 
    else 
    {
        cout << "Invalid choice. Please choose again.\n" << std::endl;
        return PlayerTurn(playerIndex);
    }
    return true;
}

bool Deck::isValidPlay(int card, std::list<int> hand) 
{
    //example logic: Check if the card exists in the player's hand
    for (int currentCard : hand) 
    {
        //checks to see if the card is the card in the deck
        if (currentCard == card) 
        {
            //checks to see if the card chosen is greater than the card inputted
            if (currentCard > hand.front())
            {
                return true;
            }
            //if the card that is inputted is not greater, returns a false value
            else 
            {
                return false;
            }
        }
    }
    //will return false if the card in not in the player hand
    return false; 
}

void Deck::resetActivePlayers()
{
    for (int i = 0; i < 4; i++)
    {
        activePlayers[i] = true;
    }
}
    
void Deck::Menu(int choice, int input)
{
    std::list<int> hand;
    
    do
    {
        cout << "Welcome to Tiến lên (Thirteen)! \n";
        cout << "If this is your first time playing, I recommend setting up a profile! \n\n";
        cout << "1. Play Game \n";
        cout << "2. Make/View Profile \n";
        cout << "3. How to play/instructions \n";
        cout << "4. Quit \n";  
    
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                GameLoop();
                break;
            case 2:
                cout << "Profile setup/viewing selected.\n";
                cout << "Sorry this part is not yet properly set up\n\n";
                break;
            case 3:
                Instructions();
                break;
            case 4:
                cout << "Exiting Game, Come back soon!\n";
                break;
            default:
                cout << "\nINVALID INPUT\n";
                cout << "Choose an input between 1-4: ";
                break;
        }
    }while (choice != 4); 
}

//using cout for every time there is a new line for readability purposes in the code
void Deck::Instructions()
{
    cout << "Setup: \n"
            "The rules of the game are as follows, deal 4 players 13 cards each from a standard \n"
            "52-card deck. Deal and play is clockwise. For the first hand, the dealer is picked \n"
            "randomly; for subsequent hands, the loser of the previous hand deals. \n\n"
            
            "Cards rank (from high to low): 2 A K Q J 10 9 8 7 6 5 4 3. Within the numerical ranking, \n"
            "suits rank (from high to low): Hearts – Diamonds – Clubs – Spades. So for example \n"
            "(from higher to lower): 2♠ A♥ A♦ A♣ A♠ K♥. Thus 2♥ is the highest card and 3♠ the \n"
            "lowest. Players in turn discard single cards, or card combinations, to a central face-up \n"
            "pile. The object is to avoid being the last player to hold any cards. \n\n"
            
            "Starting: \n"
            "If the current game in the session is the first game played, the player with the 3♠ will \n"
            "start first. Since the deck of 52 cards is evenly split between 4 players, there is a \n"
            "guarantee 3♠ to start. Any subsequent games played in the same session after the first \n"
            "game will have the player who won the previous game start. This player may also play \n"
            "any card and combination of cards, but the first starting game must always start with a \n"
            "single 3♠. \n\n"
            
            "Valid cards or combinations that may be led are:\n"
            "   -A single card \n"
            "   -A pair of the same rank, as 4♠ 4♥ \n"
            "   -A triplet of the same rank, as 9♦ 9♣ 9♠ \n"
            "   -A quartet of the same rank, as A♥ A♦ A♣ A♠ \n"
            "   -A sequence of 3 or more cards, regardless of suit, as 9♣ 10♦ J♣ \n"
            "   -A double sequence of 3 or more pairs, regardless of suit, as 5♣ 5♠ 6♥ 6♦ 7♣ 7♦ \n\n"
            
            "A sequence of values cannot exceed past the highest value of 2, therefore you cannot \n"
            "chain past 2 with a 3. Example: K♣ A♦ 2♣ is valid but K♣ A♦ 2♣ 3♠ is not since it goes \n"
            "from the highest to the lowest value. \n\n"
            
            "Following: \n"
            "After the initial play, each player may either play or pass going in the order the cards \n"
            "were dealt out in with an initial starting point of whoever had the 3♠. To play, they must \n"
            "contribute a card or combination to the pile that matches the type (single, pair, etc.) of \n"
            "the one previously played, but beats it in rank. The highest-ranking card of each \n"
            "combination determines which beats which. There is no limit to what rank or suite can \n"
            "be played, but no combinations can be played unless certain conditions are met. \n\n"
            "Passing and playing continues around until there is a card or combination that no one \n"
            
            "can beat. Once a player has passed, they may not play again to this pile, but players \n"
            "may contribute more than 1 card or combination to the pile as long as they have not yet \n"
            "passed. When the winning card or combination has been determined, its player gathers \n"
            "the pile, sets it to the side, and leads any card or combination to a fresh pile. \n\n"
            
            "At the start of a fresh pile, the game repeats similarly to how a new game would. This \n"
            "can be thought of as a “round”. Each time there is a new fresh pile, a new round starts. \n"
            "With the start of this round, the winning player of the previous round may start with any \n"
            "combination they may desire. This will be further explored in the “Tips & Tricks” section. \n\n"
            
            "Bomb/Killing the pig: \n"
            "The exceptions to the strict rule of matching type and beating rank are called bombs \n"
            "and they may be played against 2’s: \n"
            "   -A single 2 may be beaten by any double sequence of 3+ pairs, as 4♣ 4♠ 5♥ 5♦ \n"
            "    6♣ 6♦ or a quartet, as 3♥ 3♦ 3♣ 3♠ \n"
            "   -A pair of 2s may be beaten by any double sequence of 4+ pairs, as 4♣ 4♠ 5♥ \n"
            "    5♦ 6♣ 6♦ 7♠ 7♥ or a quartet, as 3♥ 3♦ 3♣ 3♠ \n"
            "   -A triplet of 2s may be beaten by any double sequence of 5+ pairs, as 4♣ 4♠ \n"
            "    5♥ 5♦ 6♣ 6♦ 7♠ 7♥ 8♦ 8♣ \n"
            "Note: The suite of the cards do not matter, just the sequence. \n\n"
            
            "Round Finish: \n"
            "As players play their last cards, they drop out of play. If the leader to a new pile has no \n"
            "cards remaining, the lead passes to the next active player to the left. The game ends \n"
            "when only one player is left with any cards. That player is the loser. In a gambling game \n"
            "the loser pays each other player a fixed stake; in a drinking game, they buy the next \n"
            "round; in a friendly game, they shuffle the deck for the next match \n\n"
            
            "If the game is to be played with multiple games in one session, players can be \n"
            "appointed points that increase by 1 based on finishing position. For example, a player \n"
            "who finishes last place gets 0 points while a player who gets first will get 3 points, \n"
            "increasing by 1 per position. This applies in standard play of 4 players, but additional \n"
            "points can be earned throughout the game with the use of the “bomb”. For each 2 that is \n"
            "beaten, a point is taken from the player and given to the player who used the “bomb”. \n\n"
            
            "Conditions: \n"
            "There are a few conditions that can make a player automatically win in the game. \n"
            "Although there are a few variations of the game, the variation we will be basing this \n"
            "upon is a mix of America and Vietnamese culture. The following implementations are \n"
            "included: \n"
            "   -Automatically win if you have a combination streak of 12 cards or above \n"
            "   -Automatically win if you have every 2 in the deck \n"
            "   -Automatically win if you have all of the same suite in your original 13 card hand \n"
            "   -If a player holds onto a 2 card and proceed to lose (being the last player to get rid \n"
            "    of all their cards), they will lose points depending on how many 2’s they held onto \n"
            "   -If you’re using a “bomb” on another player, a different player can jump in whether \n"
            "    or not they have passed their turn. They can beat your “bomb” with a better \n"
            "    version of theirs as long as the sequence is higher or of greater suite value. \n\n";
}
