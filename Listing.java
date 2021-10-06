import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Listing {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int i = 1;
        System.out.println("Start crearting the list below :");
        while (in.hasNext()) {
            String s = in.nextLine();
            System.out.println(i + " " + s);
            i++;
        }
        in.close();
    }
}
