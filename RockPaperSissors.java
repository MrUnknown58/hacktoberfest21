
package com.company;
import java.lang.Math;
import java.util.Scanner;

public class RockPaperSissors {
    static String[] str ={"Rock","Paper","Scissors"};
    static Scanner sc = new Scanner(System.in);
    static int score = 0;
    static int randomReturn (){
        return (int)(Math.random()*3+1);
    }
    static void checkInput(int n){
        while (n-- > 0) {
            int ch = sc.nextInt();                      // Gets user input.
            int rand = randomReturn(); // Generates a random number between 1-3.
            System.out.print("AI: "+str[rand-1]+"  YOU: "+str[ch-1]);
            if (rand == ch) {
                System.out.println(" [ Draw ]");
                n++;
            }
            else {
                switch (ch) {
                    case 1 -> {
                        if (rand == 2) {
                            System.out.println(" [ Lost ]");
                        }
                        else {
                            System.out.println(" [ Win ]");
                            score++;
                        }
                    }
                    case 2 -> {
                        if (rand == 3) {
                            System.out.println(" [ Lost ]");
                        } else {
                            System.out.println(" [ Win ]");
                            score++;
                        }
                    }
                    case 3 -> {
                        if (rand == 1) {
                            System.out.println(" [ Lost ]");
                        } else  {
                            System.out.println(" [ Win ]");
                            score++;
                        }
                    }
                    default -> System.out.println("Wrong choice !!!");
                }
            }
        }
    }
    public static void main(String[] args) {

        System.out.println("------------Rock Paper Scissors-----------");
        System.out.println("Best of(3/5/10) :");
        int n = sc.nextInt();
        while((n!=3)&&(n!=5)&&(n!=10)){
            System.out.println("Wrong input");
            System.out.println("Best of(3/5/10) :");
            n = sc.nextInt();
        }
        System.out.println("Enter: \n1)Rock\n2)Paper\n3)Scissors");
        checkInput(n);
        if (score >= 2)
            System.out.println("~-~-~-~YOU WON THE GAME !!~-~-~-~");
        else
            System.out.println("~-~-~-~YOU LOSE THE GAME !!~-~-~-~");
    }
}
