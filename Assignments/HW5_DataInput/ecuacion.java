/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package raices;
import java.util.Scanner;
/**
 *
 * @author andresgarcia
 */
public class ecuacion {
    public static void main(String[] args){
        double a,b,c;
        
        Scanner id= new Scanner(System.in);
        System.out.println("Ingrese a");
         a=id.nextDouble();
        System.out.println("Ingrese b");
         b=id.nextDouble();
        System.out.println("Ingrese c");
         c=id.nextDouble();
        Raices ecuacion= new Raices(a,b,c);
        ecuacion.calculate();
    }
}
