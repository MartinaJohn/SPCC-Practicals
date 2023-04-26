import java.util.*;
import java.io.*;

public class main {
    static String reg[] = new String[10];

    public static void main(String[] args) throws Exception {
        File file = new File("input.txt");
        Scanner sc = new Scanner(file);
        int count = 0;
        ArrayList<String> str = new ArrayList<String>();
        while (sc.hasNextLine()) {
            str.add(sc.nextLine());
            count++;
        }
        System.out.println(str);
        String op;
        String arg[] = new String[2];
        String result;
        for (int i = 0; i < str.size(); i++) {
            String st = str.get(i);
            String[] splited = st.split(" ");
            if (splited.length > 3) {
                op = splited[3];
                arg[0] = splited[2];
                arg[1] = splited[4];
            } else {
                op = " ";
                arg[0] = splited[2];
                arg[1] = " ";
            }
            result = splited[0];
            int temp1 = findreg(arg[0]);
            int temp2 = findreg(arg[1]);
            if (arg[1].equals(" ")) {
                System.out.println("MOV R" + temp1 + ", " + result);
            } else {
                if (temp1 == -1 && temp2 == -1) {
                    int tempreg = genreg(arg[0]);
                    System.out.println("MOV " + arg[0] + ", R" + tempreg);
                    System.out.println(generate(op) + " " + arg[1] + ", R" + tempreg);
                    reg[tempreg] = result;
                } else if (temp1 != -1 && temp2 != -1) {
                    System.out.println(generate(op) + " R" + temp1 + ", R" + temp2);
                    reg[temp2] = result;
                } else if (temp1 != -1 && temp2 == -1) {
                    int tempreg = genreg(arg[1]);
                    System.out.println("MOV " + arg[1] + ", R" + tempreg);
                    System.out.println(generate(op) + " R" + temp1 + ", R" + tempreg);
                    reg[tempreg] = result;
                } else if (temp1 == -1 && temp2 != -1) {
                    System.out.println(generate(op) + " " + arg[0] + ", R" + temp2);
                    reg[temp2] = result;
                }
            }
        }
    }

    public static int findreg(String arg) {
        int i = 0;
        while (reg[i] != null) {
            if (reg[i].equals(arg))
                return i;
            else
                i++;
        }
        return -1;
    }

    public static int genreg(String arg) {
        int i = 0;
        while (reg[i] != null)
            i++;
        reg[i] = arg;
        return i;
    }

    public static String generate(String op) {
        if (op.equals("+"))
            return "ADD";
        else if (op.equals("-"))
            return "SUB";
        else if (op.equals("*"))
            return "MUL";
        else if (op.equals("/"))
            return "DIV";
        else
            return " ";
    }
}
