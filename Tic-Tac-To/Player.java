import java.util.ArrayList;
//test
public class Player {
    private String name;
    private int money;
    private int handValue;
    private ArrayList<Card> cardsInHand;

    public Player(String name, int money){
        cardsInHand = new ArrayList<Card>();
        name = name;
        money = money;
    }

    public void setMoney(int m){
        money = m;
    }
    public int getMoney() {
        return money;
    }
    public String getName() {
        return name;
    }
}
