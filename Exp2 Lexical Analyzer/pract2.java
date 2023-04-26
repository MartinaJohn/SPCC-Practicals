import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;
public class pract2 {
 
    public static void main(String[] args) throws Exception{
        InputStream inpStream=new FileInputStream("./input.txt");
        Scanner sc=new Scanner(inpStream);
        StringBuilder sb = new StringBuilder();
        while(sc.hasNext()){
                sb.append(" "+sc.next());
        }
        String[] formatted_sb=sb.toString().split(" ");
        
        for(String s:formatted_sb){
            //System.out.println(s);
            
            if(s.matches(("[,/!%<>=*+-]"))) {
                System.out.println(s+" \t-> is an operator");
            
            }
            //operator, identifier, constants
            //variables
            else if(s.matches("[a-z]")){
                System.out.println(s+" \t-> is an identifier");
            }
            else if(s.matches("0")|| s.matches("1")||  s.matches("2") ||  s.matches("3") ||  s.matches("4") ||  s.matches("5") ||  s.matches("6") ||  s.matches("7") ||  s.matches("8") ||  s.matches("9") ||  s.matches("10") || s.matches("[A-Z]")){

                System.out.println(s+" \t-> is a constant");
            }
        
            switch(s){
                
                
                case "float":
                    System.out.println(s+" \t-> is a keyword");
                    break;
                case "char":
                    System.out.println(s+" \t-> is a keyword");
                    break;
                case "int":
                    System.out.println(s+ " \t-> is a keyword");
                    break;
                case "const":
                    System.out.println(s+ " \t-> is a keyword");
                    break;
                case "break":
                    System.out.println(s+ " \t-> is a keyword");
                    break;
                case "continue":
                    System.out.println(s+ " \t---is a keyword");
                    break;  
                
                case ";":
                    System.out.println(s+" \t-> is a special symbol");
                    break;
               
                // default:
                    
                //     System.out.println("It is a variable");
                    
            }
        }
        
    }
    
}
