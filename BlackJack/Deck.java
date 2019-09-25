import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Deck {
    private ArrayList<Card> cards;
    private ArrayList<Card> dealtCards;

    public Deck(){
        cards = new ArrayList<Card>();
        initializeDeck();
    }

    /**
     * Creates 52 unique cards of the 4 suits and
     * adds them to the deck which is then randomized
     */
    private void initializeDeck(){
        String[] faceType = {"Jack", "Queen", "King", "Ace"};
        int faceValue;
        for(int suit = 1; suit <= 4; suit++){
            for(int value = 2; value <= 10; value++){
                cards.add(new Card(value, suit));
            }
            for(int i = 0; i < 4; i++){
                faceValue = (i == 3) ? 11 : 10; // Ace card defaults to value of 11
                cards.add(new FaceCard(faceValue, suit, faceType[i]));
            }
        }
        shuffle();
    }

    /**
     * Displays each card in the deck and its info
     */
    private void displayDeck(){
        Card currentCard; FaceCard currentFCard;
        String cardInfo;
        for(int i = 0; i < 52; i++){
            currentCard = cards.get(i);
            if(currentCard.isFace){
                currentFCard = (FaceCard) currentCard;
                cardInfo = String.format("%s of %s", currentFCard.getFaceType(), currentFCard.getSuit());
            } else{
                cardInfo = String.format("%s of %s", currentCard.getValue(), currentCard.getSuit());
            }
            System.out.println((i+1)+ ". Current card is: " + cardInfo);
        }
    }

    /**
     * Randomizes the deck of cards
     */
    private void shuffle(){
        Random rand = new Random();
        Collections.shuffle(cards);
        for(int i = 0; i < 52; i++){
            Collections.swap(cards, i, rand.nextInt(52));
        }
        Collections.shuffle(cards);
    }
}
