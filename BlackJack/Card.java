public class Card {
    private String suit;
    private int value;
    protected boolean isFace;

    public Card(int v, int s){
        switch(s){
            case 1:
                suit = "spades";
                break;
            case 2:
                suit = "clubs";
                break;
            case 3:
                suit = "diamonds";
                break;
            case 4:
                suit = "hearts";
                break;
        }
        value = v;
        isFace = false;
    }
    public String getSuit(){return suit;}
    public int getValue(){return value;}
}
