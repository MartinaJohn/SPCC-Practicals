import java.io.*;
import java.util.*;
import javax.lang.model.SourceVersion;

public class lexical {
    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
        Scanner sc = new Scanner(file);
        int count = 0;
        ArrayList<String> str = new ArrayList<String>();
        while (sc.hasNextLine()) {
            str.add(sc.nextLine());
            count++;
        }
        System.out.println("Number of lines in file " + count);
        System.out.println(str);

        for (int i = 0; i < str.size(); i++) {
            String st = str.get(i);
            String[] splited = st.split(" ");
            for (int k = 0; k < splited.length - 1; k++) {
                // System.out.println(splited[k]);
                if (SourceVersion.isKeyword(splited[k]))
                    System.out.println(splited[k] + " is keyword");
                else if (SourceVersion.isIdentifier(splited[k]))
                    System.out.println(splited[k] + " is identifier");
                else if (splited[k].chars().allMatch(Character::isDigit))
                    System.out.println(splited[k] + " is Constant");
                else if (splited[k].matches("-?\\d+(\\.\\d+)?")) {
                    System.out.println(splited[k] + " is Constant");
                } else if (splited[k] == "+" || splited[k] == "-" || splited[k] == "*" || splited[k] == "/"
                        || splited[k] == "%" || splited[k] == "=")
                    System.out.println(splited[k] + " is Operator");
                else if (splited[k].charAt(0) == '"' || splited[k].charAt(0) == '\'')
                    System.out.println(splited[k] + " is literal");
                else
                    System.out.println(splited[k] + " is a special symbol");
            }
        }
        sc.close();
    }
}