/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package soe1;

/**
 *
 * @author googler
 */
import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class SOE1 {

   public static void main(String[] args) throws IOException {
        int count;
        Matcher matcher;
        String hello = readFile("input.c");
        PrintWriter out = new PrintWriter("Rit2014036.txt");
        
        //Count for loops:--------------
       
        Pattern loopcount = Pattern.compile("(for|while)(\\s)*\\((.*)\\)");       
        matcher = loopcount.matcher(hello);
        count = 0;
        while (matcher.find())
            count++;
        out.println("Number of loops:"+count);
        
        
        //Count for conditional statements:--------------
        
        Pattern ifcount = Pattern.compile("if(.*)[(](.*)[)]|else(.*)if(.*)[(](.*)[)]|else");
        matcher = ifcount.matcher(hello);
        count = 0;
        while (matcher.find())
            count++;
        out.println("Number of conditional statements:"+count);
        
        //Count for variables:--------------
        
        String var1 = "(\\w)((\\s)*"+"="+"(\\s)*(.*))*";
        String var2 = "(int|char|double|float)"+"(\\s)+"+var1+"(\\s)*(,(\\s)*"+var1+")*;";
        Pattern varcount = Pattern.compile(var2);
        matcher = varcount.matcher(hello);
        int tot=0,dec=0;
        out.println("Variables:");
        while (matcher.find()){
            String st = hello.substring(matcher.start(), matcher.end());
            Combo cb = send(st);
            dec+=cb.second;
            tot+=cb.first;
            out.println(st);
        }
        out.println("Number of variables:\n"+"Declared:"+dec+"\n"+"Total:"+tot);
        
        //Count for Functions:--------------
        
        String s1 = "(int|double|char|float)(\\s)+(\\w)+";
        String s2 = "(int|double|char|float|void)(\\s)+(\\w)+\\((\\s)*"+s1+"(\\s)*"+"(,(\\s)*" + s1 + "(\\s)*)*\\)";
        Pattern funcount = Pattern.compile(s2);
        matcher = funcount.matcher(hello);
        count = 0;
        out.println("Functions with arguments:");
        while (matcher.find()){
            out.println(hello.substring(matcher.start(),matcher.end()));
            count++;
        }
        out.println("Number of Functions:"+count);
        out.close();
      
    }
    
    public static Combo send(String s){
        int tot=1,dec=0;
        Combo cb;
        int l=0;
        while(l<s.length()){
            if(s.charAt(l)=='=')
                dec++;
            else if(s.charAt(l)==',')
                tot++;
            l++;
        }
        cb = new Combo(tot,dec);
        return cb;
    }
    
    public static String readFile(String fileName) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        try {
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();

            while (line != null) {
                sb.append(line);
                sb.append("\n");
                line = br.readLine();
            }
            String s=sb.toString();
            //System.out.println("Our string is:"+s);
            return s;
        } finally {
            br.close();
        }
    }
}

class Combo{
    int first;
    int second;
        
    Combo(int a,int b){
        this.first=a;
        this.second=b;
    }
    
}
