import java.util.Scanner;

public class Main {

    /**
     * Takes a string and returns it underlined with hyphens
     * @param text The string to be underlined
     * @return Underlined version of the string
     */
    private static String underlineText(String text){
        String underLine = "";
        for (int i = text.length(); i > 0; i--){
            underLine = underLine + "-";
        }
        return text + "\n" + underLine;
    }

    private static int intValidation(int upperBound, Scanner input){
        int userChoice;
        String selectionStr;
        try{
            selectionStr = input.next();
            userChoice = Integer.parseInt(selectionStr); // May throw NumberFormatException
            if(userChoice > upperBound || userChoice < 1){
                throw new NumberFormatException();
            }
        }
        catch(NumberFormatException e){
            System.out.print("ERROR please make a valid selection: ");
            return intValidation(upperBound, input);
        }
        return userChoice;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Deck a = new Deck();
        int menuChoice;
        System.out.println(underlineText("Blackjack Menu"));
        System.out.println("   1. Start a new game");
        System.out.println("   2. Exit");
        System.out.print("\nEnter your selection: ");
        menuChoice = intValidation(2, input);
        switch(menuChoice){
            case 1:

                break;
            case 2:
                System.out.println("Thanks for playing . . . goodbye!");
                break;
        }


    }
}
